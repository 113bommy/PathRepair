#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010, MAXW = 3010;
int N;
int in[MAXW][MAXW];
int ps[MAXW][MAXW];
map<pair<int, int>, int> bl, tr, br, tl;
int t[MAXN], l[MAXN], b[MAXN], r[MAXN];
int up[MAXN], rig[MAXN], lef[MAXN], dow[MAXN];
void setup() {
  for (int i = 1; i < MAXW; i++) {
    for (int j = 1; j < MAXW; j++) {
      ps[i][j] = bool(in[i - 1][j - 1]) + ps[i - 1][j] + ps[i][j - 1] -
                 ps[i - 1][j - 1];
    }
  }
}
bool full(int x1, int y1, int x2, int y2) {
  return (ps[x2][y2] - ps[x1][y2] - ps[x2][y1] + ps[x1][y1] ==
          (x2 - x1) * (y2 - y1));
}
int find_up(int at) {
  if (up[at]) return up[at];
  pair<int, int> next = make_pair(l[at], t[at]);
  up[at] = t[at] - b[at];
  if (bl.count(next)) up[at] += find_up(bl[next]);
  return up[at];
}
int find_rig(int at) {
  if (rig[at]) return rig[at];
  pair<int, int> next = make_pair(r[at], b[at]);
  rig[at] = r[at] - l[at];
  if (bl.count(next)) rig[at] += find_rig(bl[next]);
  return rig[at];
}
int find_lef(int at) {
  if (lef[at]) return lef[at];
  pair<int, int> next = make_pair(l[at], t[at]);
  lef[at] = r[at] - l[at];
  if (tr.count(next)) lef[at] += find_lef(tr[next]);
  return lef[at];
}
int find_dow(int at) {
  if (dow[at]) return dow[at];
  pair<int, int> next = make_pair(r[at], b[at]);
  dow[at] = t[at] - b[at];
  if (tr.count(next)) dow[at] += find_dow(tr[next]);
  return dow[at];
}
struct pt {
  int x, y, i;
  bool st;
  pt() {}
  pt(int a, int b, int c, bool d) : x(a), y(b), i(c), st(d) {}
};
bool cmp(const pt &a, const pt &b) {
  if (a.x - a.y != b.x - b.y) return a.x - a.y < b.x - b.y;
  if (a.x != b.x) return a.x < b.x;
  return a.st > b.st;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int first, second, C, D;
    cin >> first >> second >> C >> D;
    for (int j = first; j < C; j++)
      for (int k = second; k < D; k++) {
        in[j][k] = i + 1;
      }
    bl[make_pair(first, second)] = i;
    br[make_pair(C, second)] = i;
    tr[make_pair(C, D)] = i;
    tl[make_pair(first, D)] = i;
    l[i] = first;
    b[i] = second;
    r[i] = C;
    t[i] = D;
  }
  setup();
  for (int i = 0; i < N; i++) {
    find_up(i);
    find_lef(i);
    find_rig(i);
    find_dow(i);
  }
  vector<pt> p;
  for (int i = 0; i < N; i++) p.push_back(pt(l[i], b[i], i, true));
  for (int i = 0; i < N; i++) p.push_back(pt(r[i], t[i], i, false));
  sort(p.begin(), p.end(), cmp);
  string ans = "NO";
  vector<pair<int, int> > S;
  for (int i = 0; i < p.size(); i++) {
    if (i > 0 && p[i].x - p[i].y != p[i - 1].x - p[i - 1].y) S.clear();
    if (p[i].st) {
      S.push_back(make_pair(p[i].x, min(up[p[i].i], rig[p[i].i])));
    } else {
      while (!S.empty() && S.back().first + S.back().second < p[i].x)
        S.pop_back();
      if (!S.empty() &&
          p[i].x - min(dow[p[i].i], lef[p[i].i]) <= S.back().first) {
        pair<int, int> bl(S.back().first, p[i].y - (p[i].x - S.back().first)),
            tr(p[i].x, p[i].y);
        if (!full(bl.first, bl.second, tr.first, tr.second)) continue;
        cout << "YES ";
        set<int> rects;
        for (int i = bl.first; i < tr.first; i++) {
          for (int j = bl.second; j < tr.second; j++) rects.insert(in[i][j]);
        }
        cout << rects.size() << '\n';
        for (set<int>::iterator it = rects.begin(); it != rects.end(); it++)
          cout << *it << ' ';
        cout << '\n';
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}

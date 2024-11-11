#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
vector<int> seg[(int)(1e6 + 100)];
void add(int first, int second, int xb = 0, int xe = MAXN, int ind = 1) {
  if (first < xb or first > xe) return;
  seg[ind].push_back(second);
  if (xb != xe) {
    add(first, second, xb, (xb + xe) / 2, ((ind)*2));
    add(first, second, (xb + xe) / 2 + 1, xe, ((((ind)*2)) + 1));
  }
}
int bs(vector<int> &vec, int beg, int end) {
  if (vec.size() == 0 or vec[vec.size() - 1] < beg or vec[0] > end) return 0;
  int d = lower_bound(vec.begin(), vec.end(), beg) - vec.begin();
  int u = upper_bound(vec.begin(), vec.end(), end) - vec.begin();
  return u - d;
}
int query(int x1, int x2, int y1, int y2, int xb = 0, int xe = MAXN,
          int ind = 1) {
  x1 = (((x1) > (xb)) ? (x1) : (xb)), x2 = (((x2) < (xe)) ? (x2) : (xe));
  if (x2 < x1) return 0;
  if (x1 == xb and x2 == xe) return bs(seg[ind], y1, y2);
  int ans = 0;
  if (xb != xe) {
    ans += query(x1, x2, y1, y2, xb, (xb + xe) / 2, ((ind)*2));
    ans += query(x1, x2, y1, y2, (xb + xe) / 2 + 1, xe, ((((ind)*2)) + 1));
  }
  return ans;
}
int xs[MAXN], ys[MAXN];
pair<int, int> pnt[MAXN];
bool ysort(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
map<int, int> xmap, ymap;
int revx[MAXN], revy[MAXN];
int n;
void make(int xs[MAXN], map<int, int> &xmap, int revx[MAXN]) {
  int last = 0;
  for (int i = 0; i < n; ++i)
    if (xmap.find(xs[i]) != xmap.end())
      xs[i] = xmap[xs[i]];
    else {
      xmap[xs[i]] = last;
      revx[last] = xs[i];
      xs[i] = last;
      last++;
    }
}
bool error;
inline int find(int fr[], int ind) {
  if (fr[ind - 1] == fr[ind]) error = true;
  return fr[ind - 1];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", xs + i, ys + i);
    pnt[i].first = xs[i], pnt[i].second = ys[i];
  }
  sort(xs, xs + n);
  sort(ys, ys + n);
  make(xs, xmap, revx);
  make(ys, ymap, revy);
  sort(pnt, pnt + n, ysort);
  for (int i = 0; i < n; ++i) add(xmap[pnt[i].first], ymap[pnt[i].second]);
  int a[3][3];
  for (int i = 0; i < 9; ++i) scanf("%d", (&a[0][0]) + i);
  sort(&a[0][0], (&a[0][0]) + 9);
  do {
    error = false;
    int uy1 = a[2][0] + a[2][1] + a[2][2];
    int uy2 = uy1 + a[1][0] + a[1][1] + a[1][2];
    int ux1 = a[0][0] + a[1][0] + a[2][0];
    int ux2 = ux1 + a[0][1] + a[1][1] + a[2][1];
    int y1 = find(ys, uy1), y2 = find(ys, uy2), x1 = find(xs, ux1),
        x2 = find(xs, ux2);
    if (error) continue;
    if (query(0, x1, y2 + 1, MAXN) == a[0][0])
      if (query(x2 + 1, MAXN, y2 + 1, MAXN) == a[0][2])
        if (query(0, x1, 0, y1) == a[2][0])
          if (query(x2 + 1, MAXN, 0, y1) == a[2][2]) {
            cout << fixed << revy[y1] + 0.5 << " " << revy[y2] + 0.5 << endl;
            cout << fixed << revx[x1] + 0.5 << " " << revx[x2] + 0.5 << endl;
            return 0;
          }
  } while (next_permutation(&a[0][0], (&a[0][0]) + 9));
  cout << -1 << endl;
  return 0;
}

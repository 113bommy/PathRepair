#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
struct rect {
  int i1, j1, i2, j2;
};
int a, b, c, d, i, j, n, m, k;
long long ans;
char mas[1111][1111];
rect ob[111];
int beg[222];
inline bool cmp(const rect &a, const rect &b) {
  if (a.j1 != b.j1)
    return a.j1 < b.j1;
  else if (a.j2 != b.j2)
    return a.j2 < b.j2;
  else if (a.i1 != b.i1)
    return a.i1 < b.i1;
  else
    return a.i2 < b.i2;
}
vector<pair<pair<int, int>, int> > cur(0), cur2(0);
vector<pair<int, int> > good;
vector<int> cs(0);
inline int sum(vector<int> &a) {
  int ans = 0;
  for (int _n(((int)((a).size()) - 1)), i(1); i <= _n; i++) ans += a[i];
  return ans;
}
inline long long calc(int l, int r) {
  cur.clear();
  for (int _n((k)-1), i(0); i <= _n; i++) {
    if (ob[i].i2 < l || ob[i].i1 >= r) continue;
    if (ob[i].i1 >= l && ob[i].i2 < r) {
      cur.push_back(make_pair(make_pair(ob[i].j1, ob[i].j2), 1));
    } else {
      cur.push_back(make_pair(make_pair(ob[i].j1, ob[i].j2), 100));
    }
  }
  if (!(int)((cur).size())) return 0;
  sort((cur).begin(), (cur).end());
  cur2.clear();
  int a = 0;
  while (a < (int)((cur).size())) {
    int b = cur[a].first.second, c = a, d = 0;
    while (c < (int)((cur).size())) {
      if (cur[c].first.first <= b) {
        b = max(b, cur[c].first.second);
        d += cur[c].second;
        c++;
      } else
        break;
    }
    cur2.push_back(make_pair(make_pair(cur[a].first.first, b), d));
    a = c;
  }
  cur = cur2;
  long long ans = 0;
  good.clear();
  cs.clear();
  good.push_back(make_pair(0, cur[0].first.first));
  cs.push_back(0);
  for (int _n(((int)((cur).size())) - 1), i(0); i <= _n; i++) {
    if (cur[i].second >= 100) {
      good.clear();
      cs.clear();
      int fr = 0;
      if (i < (int)((cur).size()) - 1) {
        fr = cur[i + 1].first.first - cur[i].first.second;
      } else {
        fr = m - cur[i].first.second;
      }
      pair<int, int> rr = make_pair(0, 0);
      rr.first = cur[i].first.second + 1;
      if (i < (int)((cur).size()) - 1)
        rr.second = cur[i + 1].first.first;
      else
        rr.second = m;
      good.push_back(rr);
      cs.push_back(cur[i].second);
      while (sum(cs) > 3) {
        good.erase(good.begin());
        cs.erase(cs.begin());
      }
    } else {
      int fr = 0;
      if (i < (int)((cur).size()) - 1) {
        fr = cur[i + 1].first.first - cur[i].first.second;
      } else {
        fr = m - cur[i].first.second;
      }
      pair<int, int> rr = make_pair(0, 0);
      rr.first = cur[i].first.second + 1;
      if (i < (int)((cur).size()) - 1)
        rr.second = cur[i + 1].first.first;
      else
        rr.second = m;
      good.push_back(rr);
      cs.push_back(cur[i].second);
      while (sum(cs) > 3) {
        good.erase(good.begin());
        cs.erase(cs.begin());
      }
      for (int _n(((int)((good).size()) - 1) - 1), j(0); j <= _n; j++)
        ans += (long long)fr * (good[j].second - good[j].first + 1);
    }
  }
  return ans;
}
int main() {
  gets(mas[0]);
  sscanf(mas[0], "%d%d%d", &n, &m, &k);
  for (int _n((n)-1), i(0); i <= _n; i++) gets(mas[i]);
  k = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    for (int _n((m)-1), j(0); j <= _n; j++) {
      if (mas[i][j] == '*' && mas[i + 1][j] != '*' && mas[i][j + 1] != '*') {
        int ci = i, cj = j;
        while (ci > 0 && mas[ci - 1][cj] == '*') --ci;
        while (cj > 0 && mas[ci][cj - 1] == '*') --cj;
        rect r;
        r.i1 = ci;
        r.i2 = i;
        r.j1 = cj;
        r.j2 = j;
        ob[k++] = r;
      }
    }
  }
  sort(ob, ob + k, cmp);
  c = 0;
  for (int _n((k)-1), i(0); i <= _n; i++) {
    beg[c++] = ob[i].i1;
    beg[c++] = ob[i].i2;
  }
  beg[c++] = 0;
  sort(beg, beg + c);
  c = unique(beg, beg + c) - beg;
  ans = 0;
  for (int _n((c)-1), ir(0); ir <= _n; ir++) {
    int r = beg[ir] + 1;
    long long tmp = 0;
    for (int _n((c)-1), il(0); il <= _n; il++) {
      int l = beg[il];
      if (l >= r) break;
      long long cur = calc(l, r);
      if (il)
        tmp += cur * (l - beg[il - 1]);
      else
        tmp += cur * (l + 1);
    }
    if (ir != c - 1)
      ans += tmp * (beg[ir + 1] - r + 1);
    else
      ans += tmp * (m - r + 1);
  }
  cout << ans << endl;
}

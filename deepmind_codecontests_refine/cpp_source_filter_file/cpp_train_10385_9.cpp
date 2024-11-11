#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int P = 540000;
set<int> s[P];
int ll, rr, vv, mx[P], mi[P];
int a[N], b[N], c[N], d[N];
bool del[N];
void up(int ind, int l, int r) {
  if (l ^ r) {
    mx[ind] = max(mx[ind << 1], mx[ind << 1 | 1]);
    mi[ind] = min(mi[ind << 1], mi[ind << 1 | 1]);
  } else
    mx[ind] = mi[ind] = 0;
  if (s[ind].size()) {
    int tmp = *s[ind].rbegin();
    if (del[tmp])
      mi[ind] = max(mi[ind], tmp);
    else
      mx[ind] = max(mx[ind], tmp);
  }
  if (mx[ind] < mi[ind]) mx[ind] = 0;
}
void modify(int ind, int l, int r) {
  if (ll <= l && r <= rr) {
    if (vv > 0) {
      s[ind].insert(vv);
    } else if (vv < 0)
      s[ind].erase(-vv);
    up(ind, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid) modify(ind << 1, l, mid);
  if (mid < rr) modify(ind << 1 | 1, mid + 1, r);
  up(ind, l, r);
}
map<int, int> mpx, mpy;
vector<int> e[N + N];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    mpx[a[i]] = 1;
    mpy[b[i]] = 1;
    mpx[c[i]] = 1;
    mpy[d[i]] = 1;
  }
  int szx = 0, szy = 0;
  for (map<int, int>::iterator it = mpx.begin(); it != mpx.end(); ++it) {
    it->second = ++szx;
  }
  for (map<int, int>::iterator it = mpy.begin(); it != mpy.end(); ++it) {
    it->second = ++szy;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = mpx[a[i]], b[i] = mpy[b[i]], c[i] = mpx[c[i]], d[i] = mpy[d[i]];
    e[a[i]].push_back(i);
    e[c[i] + 1].push_back(i);
  }
  int ans = 1;
  for (int i = 1; i <= szx; ++i) {
    for (auto j : e[i]) {
      ll = b[j];
      rr = d[j];
      vv = (i == a[j] ? j : -j);
      modify(1, 1, szy);
    }
    while (mx[1]) {
      ++ans;
      del[mx[1]] = 1;
      ll = b[mx[1]];
      rr = d[mx[1]];
      vv = 0;
      modify(1, 1, szy);
    }
  }
  cout << ans;
}

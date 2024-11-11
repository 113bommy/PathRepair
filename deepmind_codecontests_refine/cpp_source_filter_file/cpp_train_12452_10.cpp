#include <bits/stdc++.h>
using namespace std;
string st, tem;
vector<int> tk, point;
int sz_man, sz_point;
int ck(int md) {
  int lst = 0;
  for (int j = 0; j < sz_man; j++) {
    int man = tk[j];
    int dif = max(0, man - point[lst]);
    if (dif > md) return 0;
    lst = lower_bound(point.begin(), point.end(), man) - point.begin();
    if (lst == sz_point) return 1;
    int start = lst;
    for (int i = start; i < sz_point; i++) {
      int now = point[i];
      int a = dif * 2 + now - man;
      int b = (now - man) * 2 + dif;
      lst = i;
      if (min(a, b) > md) break;
      if (i == sz_point - 1) return 1;
    }
    if (point[lst - 1] > man) {
      for (int i = j; i < sz_man; i++) {
        if (tk[i] > point[lst - 1]) break;
        j = max(j, i - 1);
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, l, u, v, w, x, y, z, a, b, c, d, e, f, t = 1, tc;
  long long flg, sz, cnt, gt, ans, mx, mn, res;
  long long m, k, n;
  long long low, hi, md, sm, ff;
  cin >> n >> st;
  sz = st.size();
  low = 0, hi = sz * 2 + 10;
  for (i = 0; i < sz; i++) {
    if (st[i] == 'P') tk.push_back(i);
    ;
    if (st[i] == '*') point.push_back(i);
    ;
  }
  sz_man = tk.size();
  sz_point = point.size();
  ans = 0;
  while (low <= hi) {
    md = (low + hi) / 2;
    if (ck(md))
      ans = md, hi = md - 1;
    else
      low = md + 1;
  }
  cout << ans << endl;
  return 0;
}

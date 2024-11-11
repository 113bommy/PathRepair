#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, w, cur, ans[N];
int query(int r, int d) {
  cout << "? " << r << ' ' << d << endl;
  int ret;
  cin >> ret;
  swap(ret, cur);
  return cur - ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int w = n * m;
  query(0, 1);
  vector<int> st(n - 1);
  for (int i = 1; i < n; i++) st[i - 1] = i;
  query(0, 1);
  bool fl = 0;
  while (1) {
    if (query(0, 1) > 0)
      fl = 1;
    else if (fl)
      break;
  }
  query(0, -1);
  for (int i = 0; i < w; i++) {
    if (query(0, 1) > 0) {
      fl = 1;
      continue;
    } else if (!fl)
      continue;
    if (st.empty()) continue;
    query(0, -1);
    int l = 0, r = st.size();
    bool out = 0;
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      if (!out)
        for (int j = mid; j < r; j++) query(st[j], -1);
      else
        for (int j = l; j < mid; j++) query(st[j], 1);
      if (query(0, -1) < 0)
        r = mid, out = 0;
      else
        l = mid, out = 1;
      query(0, 1);
    }
    int pos = st[l];
    for (int j = out - 1; j < m; j++) query(pos, -1);
    ans[pos] = (i - m - 1 + w) % w;
    st.erase(st.begin() + l);
    --i;
    query(0, -1);
    fl = query(0, 1) > 0;
  }
  cout << "! ";
  for (int i = 1; i < n; i++) cout << ans[i] << ' ';
  return 0;
}

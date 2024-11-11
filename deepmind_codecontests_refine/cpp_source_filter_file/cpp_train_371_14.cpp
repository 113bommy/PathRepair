#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, u, v, w, x, y, z, a, b, c, d, e, f, t = 1, tc;
  int flg, sz, cnt, gt, ans, mx, mn;
  int m, k, i, j;
  int low, hi, md, sm, ff;
  int n, inp[2007], ase[2007][27];
  char ch;
  string st;
  scanf("%d", &n);
  cin >> st;
  sz = st.size();
  memset(ase, 0, sizeof ase);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < sz; j++) {
      cnt = 0;
      for (int k = j; k < sz; k++) {
        if (st[k] != i + 'a') cnt++;
        ase[cnt][i] = max(ase[cnt][i], k - j + 1);
      }
    }
  }
  scanf("%lld", &tc);
  while (tc--) {
    scanf("%d", &m);
    getchar();
    m = min(m, sz);
    ch = getchar();
    x = ch - 'a';
    ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, ase[i][x]);
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int64_t const base = 1e9 + 7;
int n, q, l, r, cnt, res;
string s;
int64_t f[100005], i_th[100005];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> q >> s;
  i_th[1] = 1;
  for (int i = 2; i <= 100003; ++i) i_th[i] = (i_th[i - 1] << 1) % base;
  for (int i = 0; i < s.size(); ++i) f[i + 1] = f[i] + s[i] - '0';
  while (q--) {
    cin >> l >> r;
    cnt = f[r] - f[l - 1];
    res = (base + i_th[cnt + 1] - 1) % base;
    res += ((i_th[r - l + 1 - cnt + 1] - 1) * res) % base;
    cout << res << '\n';
  }
}

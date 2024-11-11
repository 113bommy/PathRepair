#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000012, F = 17971, MOD = 1e9 + 7;
int n, m, ps, cnt, a[maxn];
long long cn = 1, base[maxn], hsh[maxn], h1;
string p;
bool ch[maxn], c[maxn];
long long gethash(int a, int b) {
  return (hsh[b] - (hsh[a] * base[b - a]) % MOD + MOD) % MOD;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> p;
  ps = p.size();
  base[0] = 1;
  for (int i = 1; i < maxn; i++) base[i] = (base[i - 1] * F) % MOD;
  for (int i = 1; i <= ps; i++) {
    hsh[i] = ((hsh[i - 1] * F) % MOD + p[i - 1] - 'a' + 1) % MOD;
  }
  for (int i = 1; i <= ps; i++) {
    h1 = gethash(ps - i, ps);
    if (h1 == hsh[i]) ch[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    c[a[i] - 1] = 1;
  }
  ps--;
  for (int i = 1; i < m; i++) {
    if (a[i] == a[i - 1] + ps) {
      if (p[0] != p[ps]) return cout << 0, 0;
    }
    if (a[i] < a[i - 1] + ps) {
      if (ch[a[i - 1] + ps - a[i]] != 0) return cout << 0, 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (c[i] == 1) cnt = p.size();
    if (cnt <= 0) cn = (cn * 26ll) % MOD;
    cnt--;
  }
  cout << cn;
}

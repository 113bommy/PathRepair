#include <bits/stdc++.h>
using namespace std;
long long GCD(long long u, long long v) {
  long long r;
  while (v) {
    r = u % v;
    u = v;
    v = r;
  }
  return u;
}
long long modpow(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
long long power(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a);
    a = (a * a);
    p /= 2;
  }
  return ret;
}
map<char, int> m;
int a[11][11], col[111], val[111], idt[111];
int main() {
  int i, j, k, l, tmp;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, ans = 11;
  cin >> n;
  m['R'] = 0;
  m['G'] = 1;
  m['B'] = 2;
  m['Y'] = 3;
  m['W'] = 4;
  for (i = 0; i < n; i++) {
    string s;
    cin >> s;
    col[i] = m[s[0]];
    val[i] = s[1] - '0' - 1;
  }
  for (i = 0; i < 32; i++) {
    for (j = 0; j < 32; j++) {
      for (k = 0; k < n; k++) {
        int p, q, dc = (1 << col[k]), dv = (1 << val[k]);
        if (dc & i)
          p = col[k];
        else
          p = 100;
        if (dv & j)
          q = val[k];
        else
          q = 100;
        idt[k] = 101 * p + q;
      }
      bool f = 1;
      for (k = 0; k < n; k++)
        for (l = 0; l < n; l++)
          if (idt[k] == idt[l])
            if (col[k] != col[l] || val[k] != val[l]) f = 0;
      if (!f) continue;
      int temp = 0;
      for (k = 0; k < 5; k++) {
        if ((1 << k) & i) temp++;
        if ((1 << k) & j) temp++;
      }
      ans = min(ans, temp);
    }
  }
  cout << ans << '\n';
  return 0;
}

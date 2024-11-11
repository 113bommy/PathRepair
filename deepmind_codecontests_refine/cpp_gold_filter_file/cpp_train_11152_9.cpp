#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 405;
const int L = 400;
int mo;
long long f[N], g[N][N], s[N];
long long js[N], inv[N];
long long h[N];
int main() {
  int T = get();
  mo = get();
  js[0] = js[1] = 1;
  for (int i = 2; i <= L; i++) js[i] = js[i - 1] * i % mo;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= L; i++) inv[i] = 1ll * (mo - mo / i) * inv[mo % i] % mo;
  for (int i = 2; i <= L; i++) inv[i] = inv[i] * inv[i - 1] % mo;
  g[0][0] = 1;
  for (int i = 0; i <= L - 1; i++)
    for (int x = 0; x <= L; x++)
      if (g[i][x])
        for (int y = 1; y <= L - x; y++)
          g[i + 1][x + y] = (g[i + 1][x + y] + g[i][x] * js[y]) % mo;
  h[2] = 1;
  for (int i = 1; i <= L; i++) {
    f[i] = js[i];
    for (int j = 2; j <= i - 1; j++)
      f[i] = (f[i] + mo - f[j] * (g[j - 1][i - 1]) % mo) % mo;
    s[i] = f[i];
    for (int j = 3; j <= i - 1; j++)
      s[i] = (s[i] + mo - s[j] * f[i - j + 1] % mo) % mo;
    if (i > 2) {
      h[i] = (f[i - 1] + mo - h[i - 1]) % mo;
      s[i] = (s[i] + mo - h[i] * 2 % mo) % mo;
    }
  }
  for (; T; T--) {
    int n = get();
    cout << s[n] << endl;
  }
  return 0;
}

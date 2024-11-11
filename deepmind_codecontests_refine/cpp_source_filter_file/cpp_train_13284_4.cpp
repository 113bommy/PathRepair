#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = 1e18 + 10;
const int MAX = 310;
const int BASE = 1e9 + 7;
int n, ng;
int a[MAX], g[MAX], cg[MAX], fact[MAX];
int f[MAX][MAX], c[MAX][MAX];
long long mul(long long a, long long b) { return (a * b) % BASE; }
bool is_sqr(long long x) {
  long long sx = (long long)sqrt(x);
  for (int i = -2; i <= 2; i++)
    if (sx + i > 0 && ((sx + i) * (sx + i)) == x) return true;
  return false;
}
void process() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    if (g[i] == 0) {
      g[i] = ++ng;
      cg[ng] = 1;
      for (int j = i + 1; j <= n; j++)
        if (is_sqr((long long)a[i] * a[j])) {
          g[j] = ng;
          cg[ng]++;
        }
    }
  for (int i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % BASE;
  }
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
  memset(f, 255, sizeof(f));
  f[0][0] = 1;
  int total = 0;
  for (int i = 0; i < ng; i++) {
    total += cg[i];
    for (int j = 0; j < n; j++)
      if (f[i][j] != -1) {
        for (int k = 1; k <= min(total + 1, cg[i + 1]); k++)
          for (int l = 0; l <= min(j, k); l++) {
            int newj = j - l + cg[i + 1] - k;
            if (f[i + 1][newj] == -1) f[i + 1][newj] = 0;
            long long T = mul(mul(mul(c[cg[i + 1] - 1][k - 1], c[l][j]),
                                  c[total + 1 - j][k - l]),
                              fact[cg[i + 1]]);
            f[i + 1][newj] = (T * f[i][j] + f[i + 1][newj]) % BASE;
          }
      }
  }
  if (f[ng][0] == -1) f[ng][0] = 0;
  cout << f[ng][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}

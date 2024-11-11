#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const long long inf = (int)1e9 - 1;
const int N = ((int)1e5 + 10);
const int K = 70000;
const int mod = 1000000007;
const double eps = 1e-9;
inline void in() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
template <class T>
T modexp(T a, T b, T c) {
  T ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return ans;
}
template <class T>
T C(T n, T r) {
  r = min(r, n - r);
  T ans = 1;
  for (T i = 1; i <= r; i++) {
    ans *= (n - r + i);
    ans /= i;
  }
  return ans;
}
int x[N], y[N], z[N];
int main() {
  in();
  int q;
  string s;
  cin >> s;
  int n = ((int)(s).size());
  for (int i = 1; i <= n; i++) {
    x[i] = x[i - 1] + (s[i - 1] == 'x');
    y[i] = y[i - 1] + (s[i - 1] == 'y');
    z[i] = z[i - 1] + (s[i - 1] == 'z');
  }
  cin >> q;
  for (int i = 0; i <= q - 1; i++) {
    int a, b;
    cin >> a >> b;
    if (b - a <= 1) {
      puts("YES");
      continue;
    }
    int ma = max(x[b] - x[a - 1], max(y[b] - y[a - 1], z[b] - z[a - 1]));
    int mi = min(x[b] - x[a - 1], min(y[b] - y[a - 1], z[b] - z[a - 1]));
    if (ma - mi < 2)
      puts("YES");
    else
      puts("NO");
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n, k;
int Pow10[10], F[10];
long long f[N];
long long cal(int n) {
  int t = 0;
  long long s = 0;
  while (n > 0) {
    int x = n % 10;
    if (x % 3 == 0) s += 1LL * F[t] * x / 3;
    n /= 10;
    t++;
  }
  return s;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("main.in", "r")) freopen("main.in", "r", stdin);
  cin >> k;
  Pow10[0] = 1;
  for (int i = 0; i < 6; i++) {
    cin >> F[i];
    if (i) Pow10[i] = Pow10[i - 1] * 10;
  }
  for (int i = 0; i <= N - 2; i++) f[i] = -1e15;
  f[0] = 0;
  for (int t = 0; t < 6; t++) {
    int s = 0, p = 1;
    while (s + p <= 3 * (k - 1)) {
      s += p;
      for (int i = N - 2; i >= 3LL * p * Pow10[t]; i--)
        f[i] = max(f[i], f[i - 3 * p * Pow10[t]] + 1LL * p * F[t]);
      p *= 2;
    }
    s = 3 * (k - 1) - s;
    for (int i = N - 2; i >= 3LL * s * Pow10[t]; i--)
      f[i] = max(f[i], f[i - 3 * s * Pow10[t]] + 1LL * s * F[t]);
  }
  for (int t = 0; t < 6; t++) {
    for (int i = N - 2; i >= 0; i--)
      for (int j = 0; j <= 9; j++) {
        if (i < j * Pow10[t]) continue;
        int bonus = (j % 3 == 0) ? 1LL * j / 3 * F[t] : 0;
        f[i] = max(f[i], f[i - j * Pow10[t]] + bonus);
      }
  }
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    cout << f[n] << '\n';
  }
  return 0;
}

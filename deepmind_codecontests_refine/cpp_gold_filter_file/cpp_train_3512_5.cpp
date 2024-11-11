#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;
auto PI = acos(-1);
void fft(vector<cd>& a, bool inv = false) {
  int n = a.size();
  int b = __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    int idx = 0;
    for (int j = 0; j < b; ++j) idx = (idx << 1) | (i >> j & 1);
    if (i < idx) swap(a[i], a[idx]);
  }
  for (int m = 2; m <= n; m *= 2) {
    auto alpha = (inv ? -2 : 2) * PI / m;
    auto w = cd(cos(alpha), sin(alpha));
    for (int k = 0; k < n; k += m) {
      cd x = 1;
      for (int i = 0; i < (m >> 1); ++i) {
        auto u = a[k + i];
        auto v = a[k + i + (m >> 1)] * x;
        a[k + i] = u + v;
        a[k + i + (m >> 1)] = u - v;
        x *= w;
      }
    }
  }
  if (inv)
    for (auto& x : a) x /= n;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  a[0]++;
  ll z = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    sum += (v < x);
    z += a[sum]++;
  }
  int m = 1;
  while (m < 2 * a.size()) m += m;
  vector<cd> A(m), B(m);
  for (int i = 0; i < a.size(); ++i) A[i] = a[i], B[n - i] = a[i];
  fft(A);
  fft(B);
  for (int i = 0; i < A.size(); ++i) A[i] *= B[i];
  fft(A, true);
  for (int i = n; i <= n + n; ++i)
    cout << (i == n ? z : llround(A[i].real())) << " ";
}

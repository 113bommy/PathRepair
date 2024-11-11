#include <bits/stdc++.h>
const int N = 1e6 + 5;
const long long M = 1e9 + 7;
using namespace std;
string a, b;
long long c[26], t[26], f[N] = {1}, tmp, k, sm, n, m;
long long pw(long long x, long long y) {
  return y ? (y & 1 ? x * pw(x, y - 1) % M : pw(x * x % M, y >> 1)) : 1;
}
long long find(string s) {
  sm = 0, k = 1;
  for (int i = 0; i < 26; i++) t[i] = c[i];
  for (int i = 0; i < n; i++) {
    tmp = 0;
    m = s[i] - 'a';
    for (int j = 0; j < m; j++) tmp += t[j];
    sm += tmp * f[n - i - 1] % M * k % M;
    sm %= M;
    if (!t[m]) break;
    k = k * t[m]-- % M;
  }
  for (int i = 0; i < 26; i++) sm = sm * pw(f[c[i]], M - 2) % M;
  return sm;
}
int main() {
  for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % M;
  cin >> a >> b;
  n = a.size();
  for (auto i : a) c[i - 'a']++;
  cout << (find(b) - find(a) - 1) % M;
}

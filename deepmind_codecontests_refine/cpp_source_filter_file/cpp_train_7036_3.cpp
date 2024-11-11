#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& stream, const vector<T> v) {
  stream << "[ ";
  for (int i = 0; i < (int)v.size(); i++) stream << v[i] << " ";
  stream << "]";
  return stream;
}
long long fpow(long long x, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1) {
    if (p & 1) r = r * x % m;
    x = x * x % m;
  }
  return r;
}
long long inv(long long a, long long b) {
  return a < 2 ? a : ((a - inv(b % a, a)) * b + 1) / a % b;
}
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long V, N = 250, a[300];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> V;
  while (V--) {
    long double mean = 0, var = 0;
    int i;
    for (i = 1; i <= N; i++) {
      cin >> a[i];
      mean += a[i];
    }
    mean /= N;
    for (i = 1; i <= N; i++) var += (a[i] - mean) * (a[i] - mean);
    var /= (N - 1);
    if (mean >= 0.85 * var)
      cout << "poisson\n";
    else
      cout << "uniform\n";
  }
  return 0;
}

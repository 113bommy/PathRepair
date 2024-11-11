#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '{';
  for (int i = (0), __i = (((int)(vec).size())); i < __i; i++) {
    os << vec[i];
    if (i + 1 != ((int)(vec).size())) os << ',';
  }
  os << '}';
  return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &par) {
  os << '(' << par.first << ',' << par.second << ')';
  return os;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
template <class T>
T sqr(T x) {
  return x * x;
}
const long long MOD = 1e9 + 7;
long long bin_pow(long long base, long long p) {
  if (p == 1) return base;
  if (p % 2 == 0) {
    long long t = bin_pow(base, p / 2);
    return t * t % MOD;
  } else
    return bin_pow(base, p - 1) * base % MOD;
}
long long inverse_element(long long x) { return bin_pow(x, MOD - 2); }
long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) { return (MOD + a - b) % MOD; }
long long divide(long long a, long long b) {
  return a * inverse_element(b) % MOD;
}
long long mult(long long a, long long b) { return (a * b) % MOD; }
int p[101010];
int q[101010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  if (N & 1)
    cout << "NO\n";
  else {
    cout << "YES\n";
    int n = N;
    while (n > 0) {
      int M = 1;
      while (M <= n) M <<= 1;
      M >>= 1;
      int s = 2 * M - n - 1;
      for (int i = (0), __i = (n - s + 1); i < __i; i++) p[s + i] = n - i;
      n = 2 * M - n - 2;
    }
    for (int i = (0), __i = (N); i < __i; i++) cout << p[i + 1] << ' ';
    cout << endl;
  }
  if (N < 6)
    cout << "NO";
  else if (N == 6) {
    cout << "YES\n";
    cout << "5 3 2 6 1 4";
  } else if (N == 7) {
    cout << "YES\n";
    cout << "5 3 2 6 7 4 1";
  } else {
    if ((N & (N - 1)) == 0)
      cout << "NO";
    else {
      cout << "YES\n";
      int M = 1;
      while (M <= N) M <<= 1;
      int n = N;
      while (true) {
        M >>= 1;
        if (M < 8) break;
        q[n] = M;
        while (--n >= M) q[n] = n + 1;
      }
      q[1] = 5;
      q[2] = 3;
      q[3] = 2;
      q[4] = 6;
      q[5] = 7;
      q[6] = 4;
      q[7] = 1;
      for (int i = (0), __i = (N); i < __i; i++) cout << q[i + 1] << ' ';
    }
  }
  return 0;
}

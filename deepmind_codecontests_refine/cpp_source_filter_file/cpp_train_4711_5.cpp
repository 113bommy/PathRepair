#include <bits/stdc++.h>
#pragma GCC optimize("O0")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
long long n, m, a, b, c, k, temp, x, y;
const int MAXN = 100000 + 11;
inline void read(vector<long long> &v);
inline long long max(long long a, long long b);
inline long long min(long long a, long long b);
inline long long gcd(long long a, long long b);
void solveforthiscase(const int &test) {
  cin >> n;
  vector<long long> v(n);
  read(v);
  sort(v.begin(), v.end());
  long long mi = 1000000000000000000;
  for (int i = 0; i < n; i++) mi = min(mi, v[i + 1] - v[i]);
  cout << mi << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t start, end;
  start = clock();
  int test = 1;
  cin >> test;
  for (int i = 1; i <= test; i++) {
    solveforthiscase(i);
  }
  end = clock();
  long double time_taken =
      (long double)(end - start) / (long double)(CLOCKS_PER_SEC);
  cerr << "Time taken by program is : " << (long double)time_taken * 1000
       << " milisec ";
}
inline long long max(long long a, long long b) { return ((a > b) ? a : b); }
inline long long min(long long a, long long b) { return ((a > b) ? b : a); }
inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
inline void read(vector<long long> &v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}

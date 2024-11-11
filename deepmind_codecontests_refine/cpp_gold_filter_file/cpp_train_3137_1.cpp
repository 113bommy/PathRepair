#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
inline long long add(long long a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline long long sub(long long a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
  return a;
}
inline long long mul(long long a, long long b) {
  return (long long)a * b % 1000000007;
}
inline long long mpow(long long base, long long ex,
                      long long moda = 1000000007) {
  long long res = 1;
  while (ex > 0) {
    if (ex & 1) res = (long long)res * base % moda;
    base = (long long)base * base % moda;
    ex >>= 1;
  }
  return res;
}
void solve_util(long long n, long long cur) {}
void solve() {
  string str;
  cin >> str;
  long long n = str.length();
  long long arr[26] = {0};
  for (long long i = 0; i < n; i++) {
    arr[str[i] - 'a']++;
  }
  long long c = 0, c1 = 0;
  for (long long i = 0; i <= 25; i++) {
    if (arr[i] > 0) {
      c1++;
    }
  }
  if (c1 == 1) {
    cout << "-1\n";
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (str[i] != str[n - i - 1]) {
      cout << str << "\n";
      return;
    }
  }
  sort(str.begin(), str.end());
  cout << str << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(20);
  srand(time(nullptr));
  long long t = 1;
  cin >> t;
  time_t time_t1, time_t2;
  time_t1 = clock();
  while (t--) solve();
  time_t2 = clock();
  return 0;
}

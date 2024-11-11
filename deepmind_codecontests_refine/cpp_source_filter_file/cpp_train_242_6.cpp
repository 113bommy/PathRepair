#include <bits/stdc++.h>
using namespace std;
inline bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a * b / gcd<T>(a, b);
}
template <class T>
inline T power(T b, T p) {
  long long ans = 1;
  while (p--) ans *= b;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  if (n == 1 || n == 2) cout << n;
  if (n % 3 == 0 && n % 2 == 0)
    cout << (n - 1) * (n - 2) * (n - 3);
  else if (n % 2 == 0)
    cout << (n - 1) * (n) * (n - 3);
  else
    cout << n * (n - 1) * (n - 2);
}

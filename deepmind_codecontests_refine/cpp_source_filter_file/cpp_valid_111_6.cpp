#include <bits/stdc++.h>
using namespace std;
template <typename T>
T powe(T a, T b) {
  if (b == 0) return 1;
  T x = powe(a, b / 2) % 1000000007;
  x = (x * x) % 1000000007;
  if (b & 1) x = (x * (a % 1000000007)) % 1000000007;
  return x;
}
void fun(long long int n) {
  for (long long int i = 0; i < n; i++) {
    cout << "(";
  }
  for (long long int i = 0; i < n; i++) {
    cout << ")";
  }
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i <= n; i++) {
    fun(i);
    fun(n - i);
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

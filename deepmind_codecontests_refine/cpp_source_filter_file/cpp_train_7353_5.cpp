#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 5;
const int MOD = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a % b, b);
  return gcd(a, b % a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool prime(long long a) {
  for (long long i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}
int a[100005];
void solve() {
  int n, x;
  int i, j, mx = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    mx = max(mx, x);
    a[x]++;
  }
  for (i = 1; i <= 100000; i++) {
    if (a[mx] % 2) {
      cout << "Conan" << endl;
      return;
    }
  }
  cout << "Agasa" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1, tt;
  for (tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
}

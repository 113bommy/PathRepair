#include <bits/stdc++.h>
const int mod = 1000000007;
using namespace std;
int gcd(int a, int b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (a == 0) return b;
  return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
bool check(int num) {
  while (num != 0) {
    if (num % 10 == 8) {
      return true;
    }
    num /= 10;
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= 16; i++) {
    cnt++;
    if (check(n + i)) {
      cout << cnt << '\n';
      return;
    }
  }
  cout << cnt << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

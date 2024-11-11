#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long fact(long long n) {
  if (!n) return 1;
  return n * fact(n - 1);
}
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
int getValue(int a, int b, int k, int n) {
  b -= 1;
  return (b - a) / (k + 1);
}
void solve(int tc = 0) {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  k = min(k, n - 1);
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') ones.push_back(i + 1);
  }
  int ans = 0;
  if (ones.empty()) {
    cout << 1 + (n - 1) / (k + 1) << "\n";
  } else {
    ans += (ones[0] - 1) / (k + 1);
    ans += (n - ones[ones.size() - 1]) / (k + 1);
    for (int i = 0; i < ones.size() - 1; i++)
      ans += getValue(ones[i], ones[i + 1], k, n);
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
  return 0;
}

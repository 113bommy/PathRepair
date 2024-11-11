#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<int> dp, vis;
void solve(int i) {
  if (i == 1) {
    return;
  }
  if (isPrime(i)) {
    dp[i] = i + 1;
    return;
  }
  long long val = 0;
  for (int j = i - 1; j >= 2; j--) {
    if (i % j == 0) {
      val = j;
      break;
    }
  }
  solve(val);
  solve(i / val);
  dp[i] = i + max(dp[val], dp[i / val]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  int n;
  while (t--) {
    cin >> n;
    long long ans = n;
    for (int i = 2; i * i <= n;) {
      if (n % i)
        i++;
      else {
        ans += (n / i);
        n /= i;
      }
    }
    cout << ans;
  }
  return 0;
}

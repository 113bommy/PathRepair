#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
long long int n;
long long int dp[30];
bool check(long long int m) {
  long long int num = ((m) * (m - 1)) / 2;
  return (num <= n);
}
long long int binsrc() {
  long long int l = 0, r = 1000000007;
  long long int ans = 0;
  while (l <= r) {
    long long int mid = (l + r) / 2;
    bool res = check(mid);
    if (res) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
void solve() {
  cin >> n;
  if (n == 0) {
    cout << 'a';
    return;
  }
  for (long long int i = 1; i <= 26; i++) {
    if (n == 0) {
      break;
    }
    long long int num = binsrc();
    n = n - ((num) * (num - 1)) / 2;
    dp[i] = num;
  }
  for (long long int i = 1; i <= 26; i++) {
    for (long long int j = 1; j <= dp[i]; j++) {
      cout << char(i - 1 + 'a');
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    solve();
    cout << "\n";
  }
}

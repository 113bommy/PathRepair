#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
bool vis[31624 + 1];
int factorize(int n) {
  int count = 0;
  for (auto x : primes) {
    if (n < x) break;
    while (n % x == 0) {
      n = n / x;
      count++;
    }
  }
  if (n > 1) count++;
  return count;
}
void seive(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (!vis[i]) {
      for (int j = i * i; j <= n; j += i) {
        vis[j] = 1;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) primes.push_back(i);
  }
}
long long int calculatepower(long long int A, long long int B) {
  if (B == 0)
    return 1;
  else if (B % 2 == 0)
    return calculatepower((A * A) % 1000000007, B >> 1) % 1000000007;
  else
    return (A * calculatepower((A * A) % 1000000007, B >> 1) % 1000000007);
}
long long int fastExp(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b = b >> 1;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      ans += a[i] + 1;
    } else {
      if (a[i] == a[i - 1]) {
        ans += 2;
      } else if (a[i] > a[i - 1]) {
        ans += (a[i] - a[i - 1]) + 2;
      } else {
        ans += (a[i - 1] - a[i]) + 2;
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
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
int arr[MAX * 2 + 1][5];
int tot[MAX * 2 + 1];
int helper(int ch, int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(arr[i][ch] - (tot[i] - arr[i][ch]));
  }
  sort(v.begin(), v.end(), greater<int>());
  int count = 0;
  int curr = 0;
  for (auto x : v) {
    curr += x;
    if (curr > 0) count++;
  }
  return count;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    tot[i] = 0;
    for (int j = 0; j < 5; j++) arr[i][j] = 0;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    tot[i] = (int)s.size();
    for (int j = 0; j < 5; j++) {
      arr[i][s[j] - 'a']++;
    }
  }
  int ans = INT_MIN;
  for (int i = 0; i < 5; i++) {
    ans = max(ans, helper(i, n));
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

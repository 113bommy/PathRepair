#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;
long long int n, k, M, arr[nax];
long long int solve(vector<long long int> v, long long int money) {
  long long int ans = 0;
  sort(v.begin(), v.end());
  long long int spent = 0;
  for (auto x : v) {
    if (spent + x > money) break;
    spent += x;
    ans++;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> M;
  long long int sum = 0;
  for (int i = 1; i <= k; i++) cin >> arr[i], sum += arr[i];
  long long int ans = 0;
  for (int i = 0; i <= n; i++) {
    long long int cur = (sum * i);
    if (cur > M) continue;
    long long int left = M - cur;
    long long int curscore = (k + 1) * i;
    vector<long long int> v;
    for (int j = i + 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) v.push_back(arr[k]);
    }
    curscore += solve(v, left);
    ans = max(ans, curscore);
  }
  cout << ans;
  return 0;
}

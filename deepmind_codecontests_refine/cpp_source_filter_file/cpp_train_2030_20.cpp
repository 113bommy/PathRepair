#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
map<int, int> fr;
int a[N];
int dp[N][N];
int solve(int i, int sum, int yes, int n, int m) {
  if (sum % m == 0 && yes) return 1;
  if (i == n) return 0;
  if (dp[i][sum] != -1) return dp[i][sum];
  int ans = 0;
  for (int j = 0; j <= fr[a[i]]; j++) {
    int x = sum + a[i] * j;
    ans |= solve(i + 1, x, yes | j, n, m);
  }
  return dp[i][sum] = ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  set<int> s;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.insert(x % m);
    fr[x % m]++;
  }
  set<int>::iterator it;
  int idx = 0;
  for (it = s.begin(); it != s.end(); ++it) a[idx++] = *it;
  if (n > m) {
    cout << "NO";
    return 0;
  }
  if (solve(0, 0, 0, idx, m))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

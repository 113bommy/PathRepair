#include <bits/stdc++.h>
using namespace std;
const int N = 102;
long long dp[N][N][N];
int memo[N], arr[N];
vector<int> v;
string s;
int n;
int getVal(int x) {
  if (x == 0) return 0;
  int &ret = memo[x];
  if (~ret) return ret;
  ret = arr[x];
  for (int i = 1; i < x; i++) {
    ret = max(ret, getVal(i) + getVal(x - i));
  }
  return ret;
}
long long solve(int l, int r, int cnt) {
  if (l == r) return getVal(cnt + v[l]);
  long long &ret = dp[l][r][cnt];
  if (~ret) return ret;
  ret = getVal(cnt) + solve(l + 1, r, 0);
  for (int i = l + 2; i <= r; i += 2) {
    ret = max(ret, solve(l + 1, i - 1, 0) + solve(i, r, cnt + v[l]));
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      v.push_back(cnt);
      cnt = 1;
    }
  }
  v.push_back(cnt);
  memset(memo, -1, sizeof memo);
  memset(dp, -1, sizeof dp);
  cout << solve(0, v.size() - 1, 0) << "\n";
  return 0;
}

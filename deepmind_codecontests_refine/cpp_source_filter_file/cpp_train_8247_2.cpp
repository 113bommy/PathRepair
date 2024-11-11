#include <bits/stdc++.h>
using namespace std;
const int N = 2048;
int dp[N][N];
int sorted[N][N];
string strs[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                   "1101011", "1101111", "1010010", "1111111", "1111011"};
int cts[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int wtf(string& s) {
  int r = 0;
  for (auto c : s)
    if (c == '1') r++;
  return r;
}
int best(string& s, int use) {
  int ans = -1;
  for (int i = 0; i < 10; i++) {
    bool ok = true;
    int ct = 0;
    for (int j = 0; j < 7; j++) {
      if (s[j] == '1' && strs[i][j] == '0')
        ok = false;
      else if (s[j] == '0' && strs[i][j] == '1')
        ct++;
    }
    if (ok && ct == use) {
      ans = i;
    }
  }
  return ans;
}
int g;
bool cmp(int idx1, int idx2) {
  if (sorted[g][idx1] < sorted[g][idx2]) return true;
  if (sorted[g][idx1] > sorted[g][idx2]) return false;
  return dp[g][idx1] < dp[g][idx2];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof dp);
  memset(sorted, -1, sizeof sorted);
  int n, k;
  cin >> n >> k;
  vector<string> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  dp[0][0] = 0;
  sorted[0][0] = 0;
  for (int i = 0; i < n; i++) {
    string& s = nums[i];
    vector<int> trans;
    for (int j = 0; j < 8; j++) {
      trans.push_back(best(s, j));
    }
    for (int j = 0; j < k; j++) {
      if (dp[i][j] == -1) continue;
      for (int w = 0; w < 8; w++) {
        if (trans[w] == -1) continue;
        if (sorted[i][j] > sorted[i + 1][j + w]) {
          dp[i + 1][j + w] = trans[w];
          sorted[i + 1][j + w] = sorted[i][j];
        }
      }
    }
    vector<int> to;
    for (int j = 0; j < k; j++)
      if (dp[i + 1][j] != -1) to.push_back(j);
    g = i + 1;
    sort(to.begin(), to.end(), cmp);
    for (int j = 0; j < to.size(); j++) sorted[i + 1][to[j]] = j;
  }
  if (dp[n][k] == -1) {
    cout << "-1\n";
    exit(0);
  }
  string ans = "";
  for (int i = n; i > 0; i--) {
    char c = dp[i][k] + '0';
    ans += c;
    k -= (cts[dp[i][k]] - wtf(nums[i - 1]));
  }
  assert(k == 0);
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}

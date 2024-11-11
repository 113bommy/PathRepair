#include <bits/stdc++.h>
using namespace std;
int a[509][509];
int path[509][509];
int dp[509][509];
bool flag[509];
string s;
int k;
vector<int> vec;
int main() {
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int l = i, r = j;
      while (l < r) {
        if (s[l] != s[r]) a[i][j]++;
        l++;
        r--;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = a[0][i];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < k; j++) {
      for (int l = 0; l < i; l++) {
        if (dp[l][j - 1] + a[l + 1][i] < dp[i][j]) {
          dp[i][j] = dp[l][j - 1] + a[l + 1][i];
          path[i][j] = l;
        }
      }
    }
  }
  int ans = 1 << 29;
  for (int i = 0; i <= k; i++) {
    if (ans > dp[n - 1][i]) {
      ans = dp[n - 1][i];
      vec.clear();
      int tmp = path[n - 1][i];
      int tt = i;
      vec.push_back(n - 1);
      while (tt--) {
        vec.push_back(tmp);
        tmp = path[tmp][tt];
      }
    }
  }
  cout << ans << endl;
  vec.push_back(-1);
  for (int i = vec.size() - 1; i > 0; i--) {
    if (i != 0) flag[vec[i]] = 1;
    int l = vec[i] + 1, r = vec[i - 1];
    while (l < r) {
      if (s[l] != s[r]) s[l] = s[r];
      l++;
      r--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
    if (flag[i]) cout << "+";
  }
  cout << endl;
  return 0;
}

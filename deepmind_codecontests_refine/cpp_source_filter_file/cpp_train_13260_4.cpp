#include <bits/stdc++.h>
using namespace std;
string str;
int dp[1000001];
int len[1000001];
int main() {
  cin >> str;
  for (int l = 0, i = str.size() - 1; i >= 0; i--) {
    if (str[i] == '0') {
      if (l && str[i - 1] != '0')
        dp[i] = 1, len[i] = ++l;
      else {
        l = 0;
      }
    } else {
      dp[i] = 1;
      len[i] = ++l;
    }
  }
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    if (dp[i]) {
      if (len[i] > 1)
        ans += 2;
      else
        ans += 1;
      int k = len[i];
      while (k) {
        if (str[i] == '0') ans++;
        k--;
        i++;
      }
      i--;
    }
  }
  cout << ans << endl;
}

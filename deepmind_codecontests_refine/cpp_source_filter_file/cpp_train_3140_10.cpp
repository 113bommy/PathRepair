#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int dp[2010][2010];
vector<int> tp;
string s;
char buf[2010];
int main() {
  int i, j, k;
  long long upd;
  scanf("%s", &buf);
  s = buf;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == '+' || s[i] == '-') {
      tp.push_back(1);
    } else if (s[i] == '*' || s[i] == '/') {
      tp.push_back(2);
    } else {
      while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
        i++;
      }
      i--;
      tp.push_back(0);
    }
  }
  for (i = tp.size() - 1; i >= 0; i--) {
    if (!tp[i]) {
      dp[i][i] = 1;
    }
    for (j = i + 1; j < tp.size(); j++) {
      if (!tp[j]) {
        upd = dp[i + 1][j] * (tp[i] == 1);
        for (k = i + 1; k < j; k++) {
          if (tp[k]) {
            upd += (long long)dp[i][k - 1] * dp[k + 1][j];
          }
        }
        upd %= 1000003;
        dp[i][j] = upd;
      }
    }
  }
  printf("%lld\n", dp[0][tp.size() - 1]);
  return 0;
}

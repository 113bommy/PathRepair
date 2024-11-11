#include <bits/stdc++.h>
using namespace std;
const int MAX_NUMBER = 4 * 100007;
char input[MAX_NUMBER];
int dp[MAX_NUMBER];
string ans[MAX_NUMBER];
int main() {
  scanf("%s", input);
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  int length = strlen(input);
  for (int i = 1; i <= length; i++) {
    if (input[i - 1] >= 'a' && input[i - 1] <= 'z') {
      int flag = 0;
      int point;
      for (int j = i; j >= 1 && i - j + 1 <= 4; j--) {
        if (input[j - 1] == '.') {
          flag = 1;
          point = j;
          break;
        }
      }
      if (flag) {
        if (input[point - 2] == '.') {
          continue;
        }
        for (int j = point - 2; point - j <= 8 && j >= 0; j--) {
          if (j != 0 && input[j - 1] == '.') {
            break;
          }
          if (dp[j] != -1) {
            dp[i] = j;
            break;
          }
        }
      }
    }
  }
  if (dp[length] == -1) {
    printf("NO\n");
  } else {
    printf("YES\n");
    int cnt_loc = length;
    int ans_number = 0;
    while (cnt_loc != 0) {
      int j = 0;
      for (int i = dp[cnt_loc] + 1; i <= cnt_loc; i++) {
        ans[ans_number].push_back(input[i - 1]);
      }
      ans_number++;
      cnt_loc = dp[cnt_loc];
    }
    for (int i = ans_number - 1; i >= 0; i--) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}

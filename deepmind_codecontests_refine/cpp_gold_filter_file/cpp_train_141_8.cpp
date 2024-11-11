#include <bits/stdc++.h>
using namespace std;
int pre[1010], Next[1010];
vector<int> length;
int dp[1010];
int main() {
  int i, j, n, x, l;
  while (cin >> n >> x) {
    int pos = -1;
    for (i = 1; i <= n; i++) {
      cin >> pre[i];
      Next[pre[i]] = i;
    }
    for (i = 1; i <= n; i++) {
      if (pre[i] == 0) {
        int cot = 0;
        j = i;
        while (j != 0) {
          cot++;
          if (j == x) {
            pos = cot;
            break;
          }
          j = Next[j];
        }
        if (j == 0) length.push_back(cot);
      }
    }
    l = length.size();
    dp[0] = 1;
    for (i = 0; i < l; i++) {
      for (j = n; j >= length[i]; j--) {
        if (dp[j - length[i]]) dp[j] = 1;
      }
    }
    for (i = 0; i <= n; i++) {
      if (dp[i]) cout << i + pos << endl;
    }
    memset(dp, 0, sizeof(dp));
    memset(Next, 0, sizeof(Next));
    length.clear();
  }
  return 0;
}

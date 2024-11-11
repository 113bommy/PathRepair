#include <bits/stdc++.h>
using namespace std;
int arr[500 + 5];
int dp[505][505];
int rec(int st, int en) {
  if (st > en) return 0;
  if (st == en) {
    return 1;
  }
  if (st + 1 == en) {
    if (arr[st] == arr[en])
      return 1;
    else
      return 2;
  }
  if (dp[st][en] != -1) return dp[st][en];
  int ret = en - st + 1;
  ret = min(ret, rec(st + 1, en) + 1);
  ret = min(ret, rec(st, en - 1) + 1);
  if (arr[st] == arr[en])
    ret = min(ret, rec(st + 1, en - 1));
  else
    ret = min(ret, rec(st + 1, en - 1) + 2);
  for (int i = st + 1; i < en; i++) {
    if (arr[st] == arr[i]) {
      if (i == st + 1) {
        ret = 1 + rec(i + 1, en);
      } else {
        ret = min(ret, rec(st + 1, i - 1) + rec(i + 1, en));
      }
    }
  }
  return dp[st][en] = ret;
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0, n - 1) << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int q[211111], q1, q2;
int dp[211111][2], cnt[211111][2];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int sz;
  cin >> sz;
  vector<int> e[2];
  e[0].resize(sz);
  for (int i = 0; i < sz; i++) cin >> e[0][i];
  cin >> sz;
  e[1].resize(sz);
  for (int i = 0; i < sz; i++) cin >> e[1][i];
  dp[0][0] = 1;
  dp[0][1] = 1;
  q[q1++] = 0;
  q[q1++] = 0;
  q[q1++] = 0;
  q[q1++] = 1;
  while (q1 != q2) {
    int x = q[q2++];
    int h = q[q2++];
    if (dp[x][h] == 1) {
      for (int i = 0; i < e[h ^ 1].size(); i++) {
        int y = x - e[h ^ 1][i];
        if (y < 0) y += n;
        if (dp[y][h ^ 1] == 0) {
          dp[y][h ^ 1] = 2;
          q[q1++] = y;
          q[q1++] = h ^ 1;
        }
      }
    } else {
      for (int i = 0; i < e[h ^ 1].size(); i++) {
        int y = x - e[h ^ 1][i];
        if (y < 0) y += n;
        if (dp[y][h ^ 1] != 0) continue;
        cnt[y][h ^ 1]++;
        if (cnt[y][h ^ 1] == e[h ^ 1].size()) {
          dp[y][h ^ 1] = 1;
          q[q1++] = y;
          q[q1++] = h ^ 1;
        }
      }
    }
  }
  for (int w = 0; w < 2; w++) {
    for (int i = 1; i < n; i++) {
      if (dp[i][w] == 2)
        cout << "Win ";
      else if (dp[i][w] == 1)
        cout << "Loose ";
      else
        cout << "Loop ";
    }
    cout << endl;
  }
  return 0;
}

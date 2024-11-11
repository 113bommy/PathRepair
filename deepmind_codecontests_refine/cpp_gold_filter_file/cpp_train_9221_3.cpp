#include <bits/stdc++.h>
using namespace std;
bool mark[1001];
int dp[2 * 500 * 1000 + 1];
vector<int> cokes;
int main() {
  int n, k;
  queue<int> q;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) {
    int j;
    scanf("%d", &j);
    mark[j] = 1;
  }
  for (int i = 0; i < 1001; i++)
    if (mark[i]) cokes.push_back(i);
  for (int i = 0; i < cokes.size(); i++) cokes[i] -= n;
  q.push(500 * 1000);
  while (!q.empty() && dp[500 * 1000] == 0) {
    int i = q.front();
    q.pop();
    for (auto j : cokes) {
      int k = i + j;
      if (k >= 0 && k <= 500 * 1000 && dp[k] == 0) {
        dp[k] = dp[i] + 1;
        q.push(k);
      }
    }
  }
  if (dp[500 * 1000] == 0) dp[500 * 1000] = -1;
  printf("%d\n", dp[500 * 1000]);
  return 0;
}

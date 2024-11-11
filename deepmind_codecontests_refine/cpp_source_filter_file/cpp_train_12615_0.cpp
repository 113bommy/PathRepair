#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
int mt[12][2100];
int mt1[12][12];
int dp1[4096][12];
int dp[4096][12];
bool visited[2000];
int sol(int mask, int ind) {
  if (ind >= m || mask == 0) return 0;
  if (dp[mask][ind] != -1) return dp[mask][ind];
  int ans = 0;
  for (int s = mask;; s = ((s - 1) & mask)) {
    ans = max(ans, dp1[s ^ mask][ind] + sol(s, ind + 1));
    if (s == 0) break;
  }
  dp[mask][ind] = ans;
  return ans;
}
int main() {
  scanf("%d", &t);
  for (int caso = 0; caso < t; caso++) {
    priority_queue<pair<int, int>> pq;
    memset(visited, false, sizeof visited);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        scanf("%d", &mt[i][j]);
        pq.push(make_pair(mt[i][j], j));
      }
    int ind = 0;
    while (ind < 12 && pq.size() > 0) {
      pair<int, int> a = pq.top();
      pq.pop();
      if (visited[a.second] == false) {
        for (int i = 0; i < n; i++) mt1[ind][i] = mt[i][a.second];
        visited[a.second] = true;
        ind++;
      }
    }
    for (int qq = 0; qq < ind; qq++) {
      for (int i = 0; i <= (1 << n) - 1; i++) {
        int mx = 0;
        for (int j = 0; j < ind; j++) {
          int aux = 0;
          for (int k = 0; k < n; k++) {
            if (((i >> k) & 1) == 1) aux += mt1[qq][(k + j) % n];
          }
          mx = max(mx, aux);
        }
        dp1[i][qq] = mx;
      }
    }
    m = ind;
    memset(dp, -1, sizeof dp);
    printf("%d\n", sol((1 << n) - 1, 0));
  }
  return 0;
}

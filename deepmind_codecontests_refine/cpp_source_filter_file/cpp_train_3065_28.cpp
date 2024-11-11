#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
vector<int> adj[100009];
int arr[100009];
int dp[100009][109];
int val(int x, int pos) {
  int p = upper_bound(adj[x].begin(), adj[x].end(), pos) - adj[x].begin();
  if (p >= (int)adj[x].size()) return 1000000007;
  return adj[x][p];
}
int main() {
  int n, m, s, e;
  scanf("%d%d%d%d", &n, &m, &s, &e);
  int sz = s / e;
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    adj[x].push_back(i);
  }
  dp[0][0] = 0;
  for (int i = 1; i <= sz; i++) dp[0][i] = 1000000007;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= sz; j++)
      dp[i][j] = min(dp[i - 1][j], val(arr[i], dp[i - 1][j - 1]));
  for (int j = sz; j >= 1; j--) {
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[i][j] == 1000000007) continue;
      if (j * e + i + dp[i][j] <= s) {
        flag = true;
        break;
      }
    }
    if (flag) {
      printf("%d\n", j);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}

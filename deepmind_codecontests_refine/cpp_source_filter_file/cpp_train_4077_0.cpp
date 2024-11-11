#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("O3")
using namespace std;
int dp[14][1 << 14][14];
int pre[14][1 << 14][14];
int ma[15][15];
vector<int> subset[1 << 14];
vector<int> path[1 << 14][14][14];
void build(int st, int n) {
  dp[st][1 << st][st] = 1;
  int N = (1 << n);
  for (int i = 1; i < N; i++) {
    if (i == (1 << st)) continue;
    for (int j = 0; j < n; j++) {
      if (j == st) continue;
      if ((i & (1 << j)) == 0) continue;
      for (int k = 0; k < n; k++) {
        if (dp[st][i - (1 << j)][k] == -1) continue;
        if (ma[k][j] == -1) continue;
        dp[st][i][j] = ma[k][j];
        pre[st][i][j] = k;
      }
    }
  }
}
void solve(int todo_mask, vector<int> &pt) {
  int n = pt.size();
  if (n < 3) return;
  int st = pt[0];
  for (int i : pt) {
    if (i == st) continue;
    if (ma[i][st] != -1 && dp[st][todo_mask][i] != -1) {
      vector<int> ans;
      ans.push_back(ma[i][st]);
      int mask = todo_mask, pos = i;
      for (int j = 1; j < n; j++) {
        ans.push_back(dp[st][mask][pos]);
        int pre_mask = mask;
        mask -= (1 << pos);
        pos = pre[st][pre_mask][pos];
      }
      subset[todo_mask] = ans;
      break;
    }
  }
}
void findpath(int todo_mask, int a, int b) {
  if (dp[a][todo_mask][b] == -1) return;
  int mask = todo_mask, pos = b, n = __builtin_popcount(todo_mask);
  vector<int> ans;
  for (int j = 1; j < n; j++) {
    ans.push_back(dp[a][mask][pos]);
    int pre_mask = mask;
    mask -= (1 << pos);
    pos = pre[a][pre_mask][pos];
  }
  path[todo_mask][a][b] = ans;
}
vector<int> submask[1 << 14];
vector<int> can[1 << 14];
int main() {
  for (int i = 0; i < (1 << 14); i++) {
    for (int j = i; j; j = i & j - 1) {
      submask[i].push_back(j);
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<int, int> > arr;
  memset(ma, -1, sizeof(ma));
  for (int i = 0; i < m; i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    first--, second--;
    ma[first][second] = i;
    ma[second][first] = i;
    arr.push_back({first, second});
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    build(i, n);
  }
  int N = (1 << n);
  for (int i = 0; i < N; i++) {
    vector<int> tmp;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        tmp.push_back(j);
        can[i].push_back(j);
      }
    }
    solve(i, tmp);
    for (int a = 0; a < n; a++)
      for (int b = a + 1; b < n; b++) {
        if (a == b) continue;
        if ((i & (1 << a)) == 0) continue;
        if ((i & (1 << b)) == 0) continue;
        findpath(i, a, b);
      }
  }
  for (int i = 0; i < N; i++) {
    if (subset[i].size() == __builtin_popcount(i)) continue;
    for (int lset : submask[i]) {
      int rset = (i ^ lset);
      if (subset[lset].size() == 0) continue;
      if (__builtin_popcount(rset) == 1) {
        int cnt = 0;
        int id = 0;
        for (int first = 0; first < n; first++) {
          if (rset & (1 << first)) {
            id = first;
            break;
          }
        }
        for (int first = 0; first < n; first++) {
          if (lset & (1 << first)) {
            if (ma[first][id] != -1) cnt++;
          }
        }
        if (cnt < 2) continue;
      }
      for (int a : can[rset]) {
        if (subset[i].size() && subset[i].size() <= __builtin_popcount(i) + 2)
          break;
        int cnt = 0;
        for (int first : can[lset]) {
          if (ma[first][a] != -1) cnt++;
        }
        if (cnt == 0) continue;
        for (int b : can[rset]) {
          if (subset[i].size() && subset[i].size() <= __builtin_popcount(i) + 2)
            break;
          int cnt = 0;
          for (int first : can[lset]) {
            if (ma[first][b] != -1) cnt++;
          }
          if (cnt == 0) continue;
          if (__builtin_popcount(rset) > 1 && path[rset][a][b].size() == 0)
            continue;
          if (subset[i].size() &&
              subset[lset].size() + 2 + path[rset][a][b].size() >=
                  subset[i].size())
            continue;
          subset[i].clear();
          if (__builtin_popcount(rset) == 1) {
            for (int first : can[lset]) {
              if (ma[first][a] == -1) continue;
              subset[i].push_back(ma[first][a]);
              if (subset[i].size() == 2) break;
            }
          } else {
            for (int first : can[lset]) {
              if (ma[first][a] != -1) {
                subset[i].push_back(ma[first][a]);
                break;
              }
            }
            for (int first : can[lset]) {
              if (ma[first][b] != -1) {
                subset[i].push_back(ma[first][b]);
                break;
              }
            }
          }
          for (int first : subset[lset]) subset[i].push_back(first);
          for (int first : path[rset][a][b]) subset[i].push_back(first);
        }
      }
    }
  }
  printf("%d\n", subset[N - 1].size());
  for (int first : subset[N - 1]) {
    printf("%d %d\n", arr[first].first + 1, arr[first].second + 1);
  }
}

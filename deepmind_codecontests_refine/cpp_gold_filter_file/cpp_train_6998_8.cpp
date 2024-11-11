#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int N, M;
pair<int, int> A[MAXN + 10];
int B[MAXN + 10];
vector<int> V[MAXN + 10], V2[MAXN + 10];
vector<int> comp;
int getcomp(int x) {
  return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
}
int dp[MAXN + 10][(1 << 8) + 10];
int solve(int pos, int mask) {
  int i, j;
  if (pos == M + 1) return 0;
  int &ret = dp[pos][mask];
  if (ret != -1) return ret;
  int flag = 0;
  int mask2 = 0, todo = 0, chg = 0;
  for (auto it : V[pos]) {
    int jt = lower_bound(V2[pos].begin(), V2[pos].end(), it) - V2[pos].begin();
    if (jt != V2[pos].size() && V2[pos][jt] == it) {
      bool t = (mask & (1 << jt));
      if (t) flag = 1 - flag;
      int kt = lower_bound(V2[pos + 1].begin(), V2[pos + 1].end(), it) -
               V2[pos + 1].begin();
      if (kt != V2[pos + 1].size() && V2[pos + 1][kt] == it && t)
        mask2 |= (1 << kt);
    } else {
      int kt = lower_bound(V2[pos + 1].begin(), V2[pos + 1].end(), it) -
               V2[pos + 1].begin();
      if (kt != V2[pos + 1].size() && V2[pos + 1][kt] == it)
        todo |= (1 << kt);
      else
        chg = 1;
    }
  }
  for (i = todo;; i = (i - 1) & todo) {
    int p = 0, k = (__builtin_popcount(i) + flag) % 2;
    if (k) p = B[pos];
    if (chg) p = B[pos];
    ret = max(ret, solve(pos + 1, mask2 | i) + p);
    if (i == 0) break;
  }
  return ret;
}
int main() {
  int i, j;
  scanf("%d%*d%*d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d%d", &A[i].first, &A[i].second), A[i].second++;
    comp.push_back(A[i].first);
    comp.push_back(A[i].second);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  M = comp.size() - 1;
  for (i = 1; i <= M; i++) B[i] = comp[i] - comp[i - 1];
  for (i = 1; i <= N; i++) {
    A[i].first = getcomp(A[i].first);
    A[i].second = getcomp(A[i].second) - 1;
  }
  for (i = 1; i <= N; i++)
    for (j = A[i].first; j <= A[i].second; j++) V[j].push_back(i);
  for (i = 1; i <= N; i++)
    for (j = A[i].first + 1; j <= A[i].second; j++) V2[j].push_back(i);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", solve(1, 0));
}

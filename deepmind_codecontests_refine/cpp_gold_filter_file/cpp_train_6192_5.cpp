#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;
const int MAXP = 12;
const int INF = 1e9;
int N, A[MAXN], C[MAXN];
int ans = INF;
vector<int> find(int num) {
  vector<int> P;
  if (num % 2 == 0) {
    P.push_back(2);
    while (num % 2 == 0) num /= 2;
  }
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      P.push_back(i);
      while (num % i == 0) num /= i;
    }
  }
  if (num > 1) P.push_back(num);
  return P;
}
vector<pair<int, int> > V;
int dp[MAXN][1 << MAXP];
int nPrime, nV;
int f(int now, int bitmask) {
  if (now == nV) {
    if (bitmask == (1 << nPrime) - 1)
      return 0;
    else
      return INF;
  }
  if (dp[now][bitmask] != -1) return dp[now][bitmask];
  int val = f(now + 1, bitmask);
  val = min(val, INF);
  val = min(val, f(now + 1, bitmask | V[now].first) + V[now].second);
  return dp[now][bitmask] = val;
}
int test(int idx) {
  vector<int> P = find(A[idx]);
  nPrime = P.size();
  V.clear();
  for (int i = idx + 1; i <= N; i++) {
    int bitmask = 0, val = C[i];
    for (int j = 0; j < P.size(); j++)
      if (A[i] % P[j] != 0) bitmask |= (1 << j);
    V.push_back(pair<int, int>(bitmask, val));
  }
  nV = V.size();
  memset(dp, -1, sizeof(dp));
  int ans = f(0, 0);
  if (ans < 0 || ans == INF)
    return INF;
  else
    return f(0, 0) + C[idx];
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= N; i++) scanf("%d", &C[i]);
  for (int i = 1; i <= N; i++) ans = min(ans, test(i));
  if (ans < 0 || ans == INF)
    printf("%d\n", -1);
  else
    printf("%d\n", ans);
  return 0;
}

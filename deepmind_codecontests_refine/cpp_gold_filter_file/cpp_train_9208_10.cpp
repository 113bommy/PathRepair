#include <bits/stdc++.h>
using namespace std;
vector<int> E[100010];
int dp[100010][2];
void add(int& a, long long b) { a = (a + b % 1000000007) % 1000000007; }
void mul(int& a, long long b) { a = (1ll * a * b % 1000000007); }
void sub(int& a, long long b) {
  a = (a - b % 1000000007 + 1000000007) % 1000000007;
}
int tmp[2];
int newtmp[2];
void solve(int i) {
  int numE = E[i].size();
  for (int x = 0; x < (numE); ++x) solve(E[i][x]);
  dp[i][0] = dp[i][1] = 0;
  memset(tmp, 0, sizeof(tmp));
  tmp[0] = 1;
  for (int x = 0; x < (numE); ++x) {
    memset(newtmp, 0, sizeof(newtmp));
    for (int p = 0; p < (2); ++p) add(newtmp[p], (tmp[p]) % 1000000007);
    for (int p1 = 0; p1 < (2); ++p1)
      for (int p2 = 0; p2 < (2); ++p2)
        add(newtmp[p1 ^ p2], 1ll * tmp[p1] * dp[(E[i][x])][p2] % 1000000007);
    memcpy(tmp, newtmp, sizeof(tmp));
  };
  for (int p = 0; p < (2); ++p) add(dp[i][p], tmp[p]);
  memset(tmp, 0, sizeof(tmp));
  tmp[0] = 1;
  for (int x = (numE - 1); x >= (0); --x) {
    memset(newtmp, 0, sizeof(newtmp));
    for (int p = 0; p < (2); ++p) add(newtmp[p], (tmp[p]) % 1000000007);
    for (int p1 = 0; p1 < (2); ++p1)
      for (int p2 = 0; p2 < (2); ++p2)
        add(newtmp[p1 ^ p2], 1ll * tmp[p1] * dp[(E[i][x])][p2] % 1000000007);
    memcpy(tmp, newtmp, sizeof(tmp));
  };
  for (int p = 0; p < (2); ++p) add(dp[i][p], tmp[p]);
  int all_even = 1;
  for (int x = 0; x < (numE); ++x) mul(all_even, (1 + dp[E[i][x]][0]));
  sub(dp[i][0], all_even);
  memset(tmp, 0, sizeof(tmp));
  tmp[0] = 1;
  for (int x = 0; x < (numE); ++x) {
    memset(newtmp, 0, sizeof(newtmp));
    int odd = dp[E[i][x]][1];
    for (int p = 0; p < (2); ++p)
      add(newtmp[p], tmp[p] + 1ll * tmp[p ^ 1] * odd);
    memcpy(tmp, newtmp, sizeof(newtmp));
  }
  sub(dp[i][1], tmp[1]);
  swap(dp[i][0], dp[i][1]);
}
int main() {
  int N, p;
  scanf("%d", &N);
  for (int i = (2); i <= (N); ++i) {
    scanf("%d", &p);
    E[p].push_back(i);
  }
  solve(1);
  int ans = (dp[1][0] + dp[1][1]) % 1000000007;
  printf("%d\n", ans);
}

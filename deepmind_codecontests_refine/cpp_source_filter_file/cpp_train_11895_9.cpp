#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
const int nax = 105;
int memo[nax][nax];
int row, col;
vector<map<int, pair<int, int>>> edges;
int dp(int l, int r) {
  if (l >= r) return 0;
  if (memo[l][r] != -1) return memo[l][r];
  int ans = 0;
  for (int k = l; k <= r; k++) {
    int temp = 0;
    for (int i = 0; i < row; i++)
      if (edges[i][k].first >= l && edges[i][k].second <= r) temp++;
    ans = max(ans, temp * temp + dp(l, k - 1) + dp(k + 1, r));
  }
  return memo[l][r] = ans;
}
int main() {
  row = nxt(), col = nxt();
  edges.resize(row);
  for (int i = 0; i < row; i++) {
    int c = nxt();
    for (int j = 0; j < c; j++) {
      int a = nxt(), b = nxt();
      a--;
      b--;
      for (int k = a; k <= b; k++) edges[i][k] = {a, b};
    }
  }
  memset(memo, -1, sizeof memo);
  printf("%d\n", dp(0, col - 1));
  return 0;
}

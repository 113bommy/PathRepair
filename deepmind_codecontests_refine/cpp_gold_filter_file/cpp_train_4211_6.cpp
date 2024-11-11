#include <bits/stdc++.h>
using namespace std;
double pi = 3.1415926536;
const int oo = (int)1e9;
const long long OO = numeric_limits<long long>::max();
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int di[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, -1, 1};
int f1[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int f2[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dp[2001][2001];
int n, k;
int solve(int x, int k) {
  if (!k) {
    return 1;
  }
  int &rem = dp[x][k];
  if (rem) {
    return rem;
  }
  for (int i = x; i <= n; i += x) {
    rem = (rem + solve(i, k - 1)) % (oo + 7);
  }
  return rem;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cout << solve(1, k);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 3e4 + 1;
int gem[N];
int memo[N][700];
int n, d;
const int ofs = 300;
int dp(int i, int j) {
  if (i >= (N - 1)) return 0;
  int x = d + j - ofs;
  if (x == 0) return -(int)1e9;
  int &ref = memo[i][j];
  if (ref != -1) return memo[i][j];
  return ref = max(dp(i + x, j),
                   max(dp(i + x + 1, j + 1), dp(i - 1 + x, j - 1))) +
               gem[i];
}
int main() {
  memset(memo, -1, sizeof memo);
  scanf("%d", &n);
  scanf("%d", &d);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    gem[x]++;
  }
  printf("%d\n", dp(d, 0 + ofs));
}

#include <bits/stdc++.h>
using namespace std;
int n;
bool H[100005];
int A[100005], B[100005], dp[100005];
int solve(int x) {
  if (dp[x] != -1) return dp[x];
  if (B[x] > 1 || !x) return dp[x] = 0;
  return dp[x] = solve(A[x]) + 1;
}
void find_way(int x) {
  if (B[x] > 1 || !x) return;
  find_way(A[x]);
  printf("%d ", x);
}
int main() {
  int x, mx = 0, bas, s;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    H[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", A + i);
    B[A[i]]++;
  }
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    if (H[i]) {
      s = solve(A[i]) + 1;
      if (s > mx) {
        mx = s;
        bas = i;
      }
    }
  }
  cout << mx << endl;
  find_way(bas);
  puts("");
  return 0;
}

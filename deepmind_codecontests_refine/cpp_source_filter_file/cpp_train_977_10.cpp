#include <bits/stdc++.h>
using namespace std;
void deba(int* a, int n) {
  cerr << "| ";
  for (int i = 0; i < (n); i++) cerr << a[i] << " ";
  cerr << "|" << endl;
}
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 30;
int a[123456];
int dp[123456];
int* p;
int main() {
  int n;
  scanf("%d", &n);
  ;
  for (int i = 0; i < (n); i++) scanf("%d", &a[i]);
  ;
  for (int i = 0; i < (n + 2); i++) dp[i] = INF;
  dp[0] = -INF;
  dp[1] = a[0];
  for (int i = (1); i <= (n - 1); i++) {
    p = lower_bound(dp, dp + n, a[i]);
    *p = a[i];
  }
  p = lower_bound(dp, dp + n, INF - 1);
  cout << p - dp - 1 << endl;
  return 0;
}

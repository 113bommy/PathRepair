#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
  return p1.first < p2.first;
}
int in[3005];
int main() {
  int n, cn;
  cn = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &in[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (in[j] > in[i]) cn += 1;
    }
  }
  double dp[cn + 1];
  dp[1] = 1.0;
  dp[0] = 0;
  for (int i = 3; i <= cn; i++) dp[i] = (dp[i - 2] + 4.0);
  printf("%0.8lf\n", dp[cn]);
  return 0;
}

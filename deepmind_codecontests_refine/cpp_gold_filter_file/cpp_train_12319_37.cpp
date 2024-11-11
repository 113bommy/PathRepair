#include <bits/stdc++.h>
using namespace std;
long long int dp[1 << 22] = {0};
long long int tp;
void rec(long long int n) {
  if (n <= 0) return;
  if (dp[n]) return;
  dp[n] = tp;
  for (int i = 0; i < 22; i++) {
    if (n & (1 << i)) {
      if (!dp[n - (1 << i)]) rec(n - (1 << i));
    }
  }
}
int main() {
  long long int mm = pow(2, 22) - 1;
  long long int n;
  scanf("%lld", &n);
  long long int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    tp = a[i];
    rec(mm - a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (dp[a[i]] == 0) dp[a[i]] = -1;
    printf("%lld ", dp[a[i]]);
  }
}

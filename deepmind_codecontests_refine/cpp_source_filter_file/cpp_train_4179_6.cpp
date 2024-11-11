#include <bits/stdc++.h>
using namespace std;
void parseArray(long long* A, long long n) {
  for (long long k = 0; k < n; k++) {
    scanf("%lld", A + k);
  }
}
long long memo[10100][16];
char s[10100];
long long A[10100];
long long n;
long long dp(long long, long long);
int main() {
  cin >> n;
  scanf("%s", s);
  parseArray(A, n);
  memset(memo, -1, sizeof memo);
  cout << dp(0, 0) << endl;
  return 0;
}
long long dp(long long idx, long long v) {
  if (idx == n) {
    if (v < 15) {
      return 0;
    } else {
      return 10000000000l;
    }
  }
  if (memo[idx][v] != -1) {
    return memo[idx][v];
  }
  long long ans = 0;
  if (s[idx] == 'h') {
    ans = ((A[idx] + dp(idx + 1, v)) < (dp(idx + 1, v | 1))
               ? (A[idx] + dp(idx + 1, v))
               : (dp(idx + 1, v | 1)));
  } else if (s[idx] == 'a' && (v & 1)) {
    ans = ((A[idx] + dp(idx + 1, v)) < (dp(idx + 1, v | 2))
               ? (A[idx] + dp(idx + 1, v))
               : (dp(idx + 1, v | 2)));
  } else if (s[idx] == 'r' && (v & 2) && (v & 1)) {
    ans = ((A[idx] + dp(idx + 1, v)) < (dp(idx + 1, v | 4))
               ? (A[idx] + dp(idx + 1, v))
               : (dp(idx + 1, v | 4)));
  } else if (s[idx] == 'd' && (v & 2) && (v & 1) && (v & 4)) {
    ans = ((A[idx] + dp(idx + 1, v)) < (dp(idx + 1, v | 8))
               ? (A[idx] + dp(idx + 1, v))
               : (dp(idx + 1, v | 8)));
  } else {
    ans = dp(idx + 1, v);
  }
  return memo[idx][v] = ans;
}

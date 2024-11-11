#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
long long dp[2001][4001], power[4001];
int query(int a, int b) {
  if (((a == 1)) && (b == 0)) {
    return 1;
  }
  if ((a < 1) && (b >= 1)) {
    return power[b];
  }
  if ((a < 0) || (b < 0)) {
    return 0;
  }
  if (dp[a][b] == -1) {
    dp[a][b] = query(a - 2, b + 1) * (a - 1) + query(a - 1, b) * (b);
    dp[a][b] = dp[a][b] % 1000000007;
    ;
  }
  return dp[a][b];
}
int main() {
  int N;
  cin >> N;
  int a[2001], o[2001];
  int sumer = 0;
  for (long long i = 0; i <= N; i++) {
    for (long long j = 0; j <= 4000; j++) {
      dp[i][j] = -1;
    }
  }
  for (long long i = 1; i <= N; i++) {
    o[i] = 0;
  }
  for (long long i = 1; i <= N; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      sumer++;
    } else {
      o[a[i]] = 1;
    }
  }
  long long sum = 1;
  power[0] = 1;
  for (long long i = 1; i <= 4000; i++) {
    power[i] = power[i - 1] * i;
    power[i] = power[i] % 1000000007;
    ;
  }
  for (long long i = 1; i <= sumer; i++) {
    sum = sum * i;
    sum = sum % 1000000007;
    ;
  }
  int sum2 = 0, pie = 0;
  for (long long i = 1; i <= N; i++) {
    if ((!o[i]) && (a[i] < 0)) {
      sum2++;
    } else if (a[i] < 0) {
      pie++;
    }
  }
  cout << query(sum2, pie) << endl;
  return 0;
}

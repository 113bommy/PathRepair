#include <bits/stdc++.h>
using namespace std;
static void dp_init(void);
static long long int dp_cnt(long long int num);
static long long int binary_search(long long int start, long long int end,
                                   long long int needed);
long long int m, k;
long long int dp[70][70];
void dp_init(void) {
  memset(dp, 0, sizeof(dp));
  for (long long int i = 0; i <= 60LL; i++) dp[i][0] = 1;
  for (long long int i = 1; i <= 60LL; i++) {
    for (long long int j = 1; j <= i; j++)
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
  }
}
long long int dp_cnt(long long int num) {
  long long int bit_found = 0;
  long long int bit_cnt = 0;
  for (long long int i = 60LL; i >= 0; i--) {
    if (num & (1LL << i)) {
      long long int j = k - bit_found;
      if (j < 0) break;
      bit_cnt += dp[i][j];
      bit_found++;
    }
  }
  return bit_cnt;
}
long long int binary_search(long long int start, long long int end,
                            long long int needed) {
  long long int bit_cnt, mid;
  dp_init();
  while (start <= end) {
    mid = (start + end) / 2;
    bit_cnt = dp_cnt(mid * 2) - dp_cnt(mid);
    if (bit_cnt < needed) {
      start = mid + 1;
    } else if (bit_cnt > needed) {
      end = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}
int main() {
  long long int mid = 1;
  cin >> m >> k;
  cout << binary_search(0, 100000000000000000LL, m) << endl;
  return 0;
}

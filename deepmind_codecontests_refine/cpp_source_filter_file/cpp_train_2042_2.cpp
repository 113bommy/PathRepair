#include <bits/stdc++.h>
using namespace std;
int a[500001];
int dp[500001];
int n;
long long sum(int b1, int b2) {
  int pos2 = upper_bound(a, a + n, b2) - a;
  int pos1 = lower_bound(a, a + n, b1) - a;
  if (pos1 > 0) {
    return dp[pos2 - 1] - dp[pos1 - 1];
  }
  return dp[pos2 - 1];
}
int interval(int b1, int b2) {
  if (b1 > b2) {
    return 0;
  }
  return upper_bound(a, a + n, b2) - lower_bound(a, a + n, b1);
}
int pr[1000001];
int main() {
  int x, y;
  int maxa = 0;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    maxa = ((a[i]) > (maxa) ? (a[i]) : (maxa));
  }
  vector<int> prime;
  for (long long i = 2; i <= 1000000; i++) {
    if (!pr[i]) {
      prime.push_back(i);
      for (long long j = i * i; j <= 1000000; j += i) {
        pr[j] = 1;
      }
    }
  }
  sort(a, a + n);
  dp[0] = a[0];
  for (int i = 1; i < n; i++) {
    dp[i] = dp[i - 1] + a[i];
  }
  long long real_ans = 987654321000000;
  for (int i = 0; i < prime.size(); i++) {
    long long ans = 0;
    int flag = 0;
    long long remove = 0;
    long long add = 0;
    int upper = maxa / prime[i] + (maxa % prime[i] == 0 ? 0 : 1);
    for (int j = 1; j <= upper; j++) {
      flag = 1;
      int gc = prime[i] * j;
      int gcm1 = prime[i] * (j - 1);
      int l1, l2, l3, l4;
      l1 = gcm1 + 1;
      l2 = gc - x / y - (x % y == 0 ? 0 : 1);
      l3 = ((gcm1 + 1) > (gc - x / y + (x % y == 0 ? 1 : 0))
                ? (gcm1 + 1)
                : (gc - x / y + (x % y == 0 ? 1 : 0)));
      l4 = gc - 1;
      remove += interval(l1, l2);
      int num = interval(l3, l4);
      if (num > 0) {
        add += y * ((long long)prime[i] * j * num - sum(l3, l4));
      }
    }
    ans += add + remove * x;
    if (flag) {
      real_ans = ((real_ans) > (ans) ? (ans) : (real_ans));
    }
  }
  printf("%I64d\n", real_ans);
  return 0;
}

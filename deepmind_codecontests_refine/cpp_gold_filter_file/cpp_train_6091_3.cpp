#include <bits/stdc++.h>
using namespace std;
long long mod = 5000000;
int n;
long long BIT[51][100001];
void update(int l, int x, long long val) {
  for (int X = x; X < 100002; X += X & -X) {
    BIT[l][X] = (BIT[l][X] + val);
  }
}
long long query_sum(int x, int l) {
  long long sum = 0;
  for (int X = x; X > 0; X -= X & -X) {
    sum = (sum + BIT[l][X]);
  }
  return sum;
}
int main() {
  int K, l, r, a, p;
  scanf("%d %d", &n, &K);
  K++;
  int t = n;
  while (t--) {
    scanf("%d", &a);
    update(1, a, 1);
    for (int k = 2; k <= K; k++) {
      long long sbseqnce_wth_sz_k_minus_1_less_than_a = query_sum(a - 1, k - 1);
      update(k, a, sbseqnce_wth_sz_k_minus_1_less_than_a);
    }
  }
  long long ans = query_sum(100000, K);
  printf("%lld\n", ans);
}

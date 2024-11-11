#include <bits/stdc++.h>
using namespace std;
const int MAX = 22;
int n, k, not0[MAX], nn;
double p[MAX];
void input() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
    if (p[i] > 0) {
      not0[nn++] = i;
    }
  }
}
double dp[1 << MAX], ans[MAX];
void solve() {
  if (k <= nn) {
    for (int i = 0; i < n; i++) {
      printf("%d ", p[i] == 0 ? 0 : 1);
    }
    puts("");
    return;
  }
  dp[0] = 1;
  for (int numBit = 1; numBit <= k; numBit++) {
    int bits[MAX];
    for (int i = 0; i < nn; i++) {
      bits[i] = i >= nn - numBit;
    }
    do {
      int mask = 0;
      for (int i = 0; i < nn; i++) mask |= bits[i] << i;
      dp[mask] = 0;
      double again = 0;
      for (int i = 0; i < nn; i++) {
        if (bits[i]) {
          again += p[not0[i]];
          dp[mask] += dp[mask ^ (1 << i)] * p[not0[i]];
        }
      }
      if (again >= 0.995) {
        dp[mask] = 1;
      } else {
        for (int i = 0; i < nn; i++) {
          if (bits[i]) {
            dp[mask] -= dp[mask ^ (1 << i)] * p[not0[i]] * p[not0[i]] /
                        (1 - again + p[not0[i]]);
          }
        }
        dp[mask] /= (1 - again);
      }
      if (numBit == k) {
        for (int i = 0; i < nn; i++) {
          if (bits[i]) {
            ans[not0[i]] += dp[mask];
          }
        }
      }
    } while (next_permutation(bits, bits + nn));
  }
  for (int i = 0; i < n; i++) {
    printf("%.10lg ", ans[i]);
  }
  puts("");
}
int main() {
  input();
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void SieveOfErat() {
  bool prime[1000001];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= 1000000; p++) {
    if (prime[p] == true) {
      for (long long i = p * 2; i <= 1000000; i += p) prime[i] = false;
    }
  }
}
struct vect {
  struct vect *foll;
  long long val;
  struct vect *succ;
};
int add(int a, int b) {
  int c = a + b;
  if (c >= 1000000007) {
    c -= 1000000007;
  }
  return c;
}
int mul(int a, int b) { return (a * 1LL * b) % 1000000007; }
int pow2(int b, int e) {
  int ans = 1;
  while (e > 0) {
    if (e % 2 == 1) {
      ans = mul(ans, b);
    }
    b = mul(b, b);
    e /= 2;
  }
  return ans;
}
int inv(int a) { return pow2(a, 1000000007 - 2); }
int dp[1024][1024];
int main() {
  int k, pa, push_back;
  cin >> k >> pa >> push_back;
  for (int i = 0; i < k; i++) {
    dp[k][i] = add(add(k, i), mul(pa, inv(push_back)));
  }
  int inv1 = inv(add(pa, push_back));
  for (int i = k - 1; i >= 0; i--) {
    for (int j = k; j >= 0; j--) {
      dp[i][j] = mul(pa, dp[i + 1][j]);
      if (i + j >= k) {
        dp[i][j] = add(dp[i][j], mul(push_back, add(i, j)));
      } else {
        dp[i][j] = add(dp[i][j], mul(push_back, dp[i][i + j]));
      }
      dp[i][j] = mul(dp[i][j], inv1);
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}

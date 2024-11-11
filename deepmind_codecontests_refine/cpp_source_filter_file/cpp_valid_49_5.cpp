#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
vector<int> pow_3(16, 1);
static inline int weigth(int n) {
  if (n == 0) return 0;
  int res = 0;
  while (n) {
    int q = __builtin_ffs(n) - 1;
    n ^= (1 << q);
    res += pow_3[q];
  }
  return res;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(14);
  vector<long long> inv(2000003, 1);
  for (int i = 2; i < 200003; i++) {
    inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  }
  for (int i = 1; i < 16; i++) pow_3[i] = 3 * pow_3[i - 1];
  int n;
  cin >> n;
  int N = 1 << n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> masks(n, 1);
  for (int i = 1; i < n; i++) masks[i] = 1 << i;
  vector<vector<long long>> defeat_prob(n, vector<long long>(N, 1));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < N; j++) {
      if (!(j & masks[i])) {
        int least_sign_j = __builtin_ffs(j) - 1;
        defeat_prob[i][j] =
            (defeat_prob[i][j & (j - 1)] * a[least_sign_j]) % MOD;
        defeat_prob[i][j] =
            (defeat_prob[i][j] * inv[a[least_sign_j] + a[i]]) % MOD;
      }
    }
  }
  int length = 1;
  for (int i = 0; i < n; i++) length *= 3;
  vector<long long> probs(length, 1);
  vector<long long> win_prob(N, 0);
  for (int m = 0; m < N; m++) {
    int w_m = weigth(m);
    for (int s = m; s; s = (s - 1) & m) {
      int x = m ^ s;
      int w_x = weigth(x);
      int w_s = weigth(s);
      if (s == m) {
        probs[w_s] = 0;
        continue;
      }
      int ss = s;
      long long prob = 1;
      while (ss) {
        int q = __builtin_ffs(ss) - 1;
        prob = (prob * defeat_prob[q][x]) % MOD;
        ss ^= masks[q];
      }
      probs[2 * w_x + w_s] = (probs[2 * w_x] * prob) % MOD;
      probs[2 * w_m] = (probs[2 * w_m] - probs[2 * w_x + w_s] + MOD) % MOD;
    }
  }
  long long expected = 0;
  for (int m = 0; m < N; m++) {
    int count = 0;
    int mm = m;
    while (mm) {
      int q = __builtin_ffs(mm) - 1;
      count++;
      mm ^= masks[q];
    }
    int s = weigth((N - 1) ^ m);
    expected = (expected + count * probs[2 * weigth(m) + s]) % MOD;
  }
  cout << expected << "\n";
}

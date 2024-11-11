#include <bits/stdc++.h>
using namespace std;
unsigned long long MOD = 998244353;
int main() {
  int N, M, gmax = -1;
  cin >> N >> M;
  vector<pair<int, int>> l(N);
  for (int i = 0; i < N; ++i) {
    cin >> l[i].first >> l[i].second;
    gmax = max(gmax, l[i].second);
  }
  vector<bool> is_prime(gmax + 1, true);
  is_prime[1] = false;
  vector<int> mu(gmax + 1, 1);
  vector<int> prime;
  for (int i = 2; i <= gmax; ++i) {
    if (is_prime[i]) {
      prime.push_back(i);
      mu[i] = -1;
    }
    for (auto p : prime) {
      if (i * p > gmax) break;
      is_prime[i * p] = false;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      } else {
        mu[i * p] = !mu[i];
      }
    }
  }
  unsigned long long ans = 0;
  for (int i = 1; i <= gmax; ++i) {
    if (mu[i] == 0) continue;
    vector<pair<int, int>> rl(N);
    bool flag = true;
    for (int j = 0; j < N; ++j) {
      rl[j] = {(l[j].first + i - 1) / i, l[j].second / i};
      if (rl[j].first > rl[j].second) {
        flag = false;
        break;
      }
    }
    if (!flag) continue;
    int rM = M / i;
    vector<unsigned long long> ps(rM + 1, 1);
    for (int j = 0; j < N; ++j) {
      vector<unsigned long long> ps2(rM + 1, 0);
      for (int k = rl[j].first; k <= rM; ++k) {
        unsigned long long t =
            (ps[k - rl[j].first] + MOD -
             (k - rl[j].second > 0 ? ps[k - rl[j].second - 1] : 0)) %
            MOD;
        ps2[k] = (ps2[k - 1] + t) % MOD;
      }
      swap(ps, ps2);
    }
    if (mu[i] == 1) {
      (ans += ps[rM]) %= MOD;
    } else {
      (ans += MOD - ps[rM]) %= MOD;
    }
  }
  printf("%llu\n", ans);
  return 0;
}

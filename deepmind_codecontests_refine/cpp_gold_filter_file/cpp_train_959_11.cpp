#include <bits/stdc++.h>
using namespace std;
long long pow2[29];
void calcpow2() {
  pow2[0] = 1;
  for (long long i = 1; i <= 28; i++) {
    pow2[i] = pow2[i - 1] * 2;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N;
  cin >> N;
  vector<long long> a(N);
  for (auto &it : a) {
    cin >> it;
  }
  vector<long long> finalnumber(27, 0);
  vector<vector<long long>> mods(28, vector<long long>(N));
  calcpow2();
  long long evens = 0;
  long long odds = 0;
  for (long long i = 1; i < 28; i++) {
    for (long long j = 0; j < N; j++) {
      if (i == 1) {
        if (a[j] % pow2[i] == 1) {
          odds++;
        } else {
          evens++;
        }
      }
      mods[i][j] = a[j] % pow2[i];
    }
  }
  for (long long bit = 0; bit < 27; bit++) {
    sort(mods[bit + 1].begin(), mods[bit + 1].end());
    long long lb1, ub1, lb2;
    if (bit == 0) {
      long long num_one_pairs = 0;
      num_one_pairs += (odds * evens);
      if (num_one_pairs % 2 == 1) {
        finalnumber[0] = 1;
      }
      continue;
    }
    lb1 = pow2[bit];
    ub1 = pow2[bit + 1] - 1;
    lb2 = pow2[bit + 1] + pow2[bit];
    long long total = 0;
    for (auto it = mods[bit + 1].begin(); it != mods[bit + 1].end(); it++) {
      auto it2 = lower_bound(next(it), mods[bit + 1].end(), lb1 - (*it));
      auto it3 = lower_bound(next(it), mods[bit + 1].end(), ub1 - (*it) + 1);
      total += distance(it2, it3);
      auto it4 = lower_bound(next(it), mods[bit + 1].end(), lb2 - (*it));
      total += distance(it4, mods[bit + 1].end());
    }
    if (total % 2 == 1) {
      finalnumber[bit] = 1;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < 27; i++) {
    ans += pow2[i] * finalnumber[i];
  }
  cout << ans;
  return 0;
}

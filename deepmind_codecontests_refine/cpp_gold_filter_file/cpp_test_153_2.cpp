#include <bits/stdc++.h>
using namespace std;
const int64_t P = 998244353;
int main() {
  int N;
  cin >> N;
  vector<vector<int>> strings(N, vector<int>(26, 0));
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (char c : s) ++strings[i][c - 'a'];
  }
  vector<int> dpv(1 << N, 0);
  for (int mask = 1; mask < (1 << N); ++mask) {
    const int num_bits_set_mask = __builtin_popcount(mask);
    vector<int> min_count(26, 1000000);
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        for (int c = 0; c < 26; ++c) {
          min_count[c] = min(min_count[c], strings[i][c]);
        }
      }
    }
    int64_t value = 1;
    for (int c = 0; c < 26; ++c) {
      value = (value * (min_count[c] + 1)) % P;
    }
    dpv[mask] = (num_bits_set_mask % 2 == 1) ? value : -value;
  }
  for (int i = 0; i < N; ++i) {
    for (int mask = 1; mask < (1 << N); ++mask) {
      if (mask & (1 << i)) {
        dpv[mask] = dpv[mask] + dpv[mask ^ (1 << i)];
        while (dpv[mask] < 0) dpv[mask] += P;
        while (dpv[mask] >= P) dpv[mask] -= P;
      }
    }
  }
  int64_t answer = 0;
  for (int mask = 1; mask < (1 << N); ++mask) {
    const int num_bits_set_mask = __builtin_popcount(mask);
    int64_t multiplier = num_bits_set_mask;
    int64_t index_sum = 0;
    for (int i = 0; i < N; ++i) {
      if (mask & (1 << i)) {
        index_sum += (i + 1);
      }
    }
    multiplier *= index_sum;
    const int64_t sum_over_submasks = dpv[mask];
    answer ^= sum_over_submasks * multiplier;
  }
  cout << answer << endl;
}

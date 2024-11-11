#include <bits/stdc++.h>
using namespace std;
int nth_bit(int64_t num, int n) { return (num >> n) & 1; }
int pop_count(int bits) {
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
}
int main() {
  int N;
  cin >> N;
  int A[20][20];
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) A[i][j] = (s[j] == '1');
  }
  int popcnt[1 << 18];
  for (int b = 0; b < (1 << N); b++) popcnt[b] = pop_count(b);
  static uint64_t sub[1 << 18][18];
  for (int i = 0; i < N; i++) sub[1 << i][i] = 1;
  for (int b = 1; b < (1 << N); b++)
    for (int last = 0; last < N; last++)
      if (nth_bit(b, last)) {
        for (int nxt = 0; nxt < N; nxt++)
          if (nth_bit(b, nxt) == 0 && A[last][nxt])
            sub[b + (1 << nxt)][nxt] += sub[b][last];
      }
  static uint64_t psum[1 << 18][19];
  for (int b = 0; b < (1 << N); b++) {
    for (int i = 0; i < N; i++) psum[b][popcnt[b]] += sub[b][i];
  }
  for (int k = 1; k <= N; k++)
    for (int i = 0; i < N; i++)
      for (int b = 0; b < (1 << N); b++)
        if (nth_bit(b, i)) psum[b][k] += psum[b - (1 << i)][k];
  vector<vector<int>> divs[19];
  divs[0].push_back({});
  for (int s = 0; s < N; s++)
    for (auto v : divs[s]) {
      int last = v.size() ? v.back() : 1;
      for (int nxt = last; s + nxt <= N; nxt++) {
        auto v2 = v;
        v2.push_back(nxt);
        divs[s + nxt].push_back(v2);
      }
    }
  static uint64_t ans[1 << 17];
  for (auto& D : divs[N]) {
    uint64_t res = 0;
    for (int b = 0; b < (1 << N); b++) {
      uint64_t prod = 1;
      for (int a : D) prod *= psum[b][a];
      res += prod * ((N - popcnt[b]) % 2 ? -1 : 1);
    }
    do {
      int B = 0, base = 1;
      for (int a : D) {
        for (int i = 0; i < a; i++) {
          if (i < a - 1) B += base;
          base *= 2;
        }
      }
      ans[B] += res;
    } while (next_permutation(D.begin(), D.end()));
  }
  for (int i = 0; i < N - 1; i++)
    for (int b = 0; b < (1 << (N - 1)); b++)
      if (nth_bit(b, i)) ans[b - (1 << i)] -= ans[b];
  for (int b = 0; b < (1 << (N - 1)); b++) printf("%llu ", ans[b]);
  printf("\n");
  return 0;
}

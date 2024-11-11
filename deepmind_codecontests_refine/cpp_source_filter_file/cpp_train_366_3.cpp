#include <bits/stdc++.h>
using namespace std;
const int maxpow = 30;
int BiggestPower(long long x) {
  int ans = 0;
  while (x > 1) {
    x = (x >> 1);
    ++ans;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  long long k;
  cin >> k;
  int to[n];
  int w[n];
  for (int i = 0; i < n; ++i) {
    cin >> to[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  int to_pow[n][maxpow];
  long long sum_w[n][maxpow];
  int min_w[n][maxpow];
  for (int i = 0; i < n; ++i) {
    to_pow[i][0] = to[i];
    sum_w[i][0] = w[i];
    min_w[i][0] = w[i];
  }
  for (int d = 1; d < maxpow; ++d) {
    for (int i = 0; i < n; i++) {
      to_pow[i][d] = to_pow[to_pow[i][d - 1]][d - 1];
      sum_w[i][d] = sum_w[i][d - 1] + sum_w[to_pow[i][d - 1]][d - 1];
      min_w[i][d] = min(min_w[i][d - 1], min_w[to_pow[i][d - 1]][d - 1]);
    }
  }
  int to_pow_ans[n];
  long long sum_w_ans[n];
  int min_w_ans[n];
  for (int i = 0; i < n; i++) {
    to_pow_ans[i] = i;
    sum_w_ans[i] = 0;
    min_w_ans[i] = 1e+9;
  }
  while (k > 0) {
    int d = BiggestPower(k);
    long long p = 1;
    p = (p << d);
    k -= p;
    for (int i = 0; i < n; i++) {
      sum_w_ans[i] += sum_w[to_pow_ans[i]][d];
      min_w_ans[i] = min(min_w_ans[i], min_w[to_pow_ans[i]][d]);
      to_pow_ans[i] = to_pow[to_pow_ans[i]][d];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << sum_w_ans[i] << " " << min_w_ans[i] << endl;
  }
  cout << endl;
}

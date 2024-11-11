#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
template <typename T>
void ov(vector<T> &v) {
  ostream_iterator<T> out(cout, " ");
  copy(v.begin(), v.end(), out);
}
int n, k;
long double dp[1 << 21];
long double p[20];
long double ans[30];
bool ismember(int i, int j) { return i & (1 << j); }
void solve() {
  cin >> n >> k;
  int zerop = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] < 1e-10) zerop++;
  }
  k = min(k, n - zerop);
  dp[0] = 1;
  for (int i = 0; i < (1 << n); i++) {
    long double s = 1.0;
    for (int j = 0; j < n; j++) {
      if (ismember(i, j)) s -= p[j];
    }
    if (s < 1e-10 || __builtin_popcount(i) == k) {
      for (int j = 0; j < n; j++) {
        if (ismember(i, j)) {
          ans[j] += dp[i];
        }
      }
    } else {
      for (int j = 0; j < n; j++) {
        if (!ismember(i, j)) {
          dp[i | (1 << j)] += dp[i] * p[j] / s;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << setiosflags(ios::fixed) << setprecision(9) << ans[i] << endl;
}
int main() {
  solve();
  return 0;
}

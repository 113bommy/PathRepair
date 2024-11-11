#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < (int)(N); ++i) cin >> A[i];
  stack<pair<double, int>> data;
  for (int i = 0; i < (int)(N); ++i) {
    double val = A[i];
    int length = 1;
    while (!data.empty() &&
           data.top().first / data.top().second - (1e-10) > val) {
      val += data.top().first;
      length += data.top().second;
      data.pop();
    }
    data.emplace(val, length);
  }
  vector<double> ans(N);
  int cur = N - 1;
  while (!data.empty()) {
    double val;
    int length;
    tie(val, length) = data.top();
    data.pop();
    for (int i = 0; i < (int)(length); ++i) {
      ans[cur] = val / length;
      cur--;
    }
  }
  for (int i = 0; i < (int)(N); ++i)
    cout << fixed << setprecision(12) << ans[i] << '\n';
}

#include <bits/stdc++.h>
using namespace std;
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
  if (b < a) a = b;
  if constexpr (sizeof...(c) != 0) {
    amin(a, c...);
  }
  return a;
}
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
  if (b > a) a = b;
  if constexpr (sizeof...(c) != 0) {
    amax(a, c...);
  }
  return a;
}
void preSolve(int& testcases) {}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int m = b.size();
  vector<int> dp(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[j] += abs(a[i] - b[j]);
      if (j > 0) {
        amin(dp[j], dp[j - 1]);
      }
    }
  }
  cout << *min_element(dp.begin(), dp.end());
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int testcases = 1;
  preSolve(testcases);
  for (int caseno = 1; caseno <= testcases; ++caseno) {
    solve();
  }
  return 0;
}

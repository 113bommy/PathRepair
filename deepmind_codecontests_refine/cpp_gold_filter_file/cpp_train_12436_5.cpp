#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<int> prefix(const T &v) {
  int n = v.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && v[i] != v[j]) {
      j = pi[j - 1];
    }
    if (v[i] == v[j]) {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m);
  n--, m--;
  int pre, x;
  cin >> pre;
  for (int i = 0; i < n; i++) {
    cin >> x;
    A[i] = x - pre;
    pre = x;
  }
  cin >> pre;
  for (int i = 0; i < m; i++) {
    cin >> x;
    B[i] = x - pre;
    pre = x;
  }
  if (m == 0) {
    cout << n + 1 << '\n';
    return 0;
  }
  vector<int> S(n + m + 1);
  for (int i = 0; i < m; i++) {
    S[i] = B[i];
  }
  S[m] = 1e9;
  for (int i = 0; i < n; i++) {
    S[i + m + 1] = A[i];
  }
  vector<int> pi = prefix(S);
  int ans = count_if(pi.begin(), pi.end(), [&](int x) { return x == m; });
  cout << ans << '\n';
  return 0;
}

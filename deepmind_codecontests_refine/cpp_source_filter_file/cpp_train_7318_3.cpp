#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool chmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
  sort(begin(v), end(v), f);
  v.resize(unique(begin(v), end(v)) - begin(v));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < (int)(n); i++) {
    int k;
    cin >> k;
    a[i].resize(k);
    for (int j = 0; j < (int)(k); j++) cin >> a[i][j];
  }
  vector<vector<int>> v(n);
  for (int i = 0; i < (int)(n); i++) {
    int k = a[i].size();
    v[i].resize(k + 1);
    for (int j = 1; j <= (int)(k); j++) {
      int sum = 0;
      for (int x = 0; x < (int)(j); x++) sum += a[i][x];
      chmax(v[i][j], sum);
      for (int x = 0; x < (int)(j); x++) {
        sum += a[i][k - x - 1] - a[i][j - x - 1];
        chmax(v[i][j], sum);
      }
    }
  }
  vector<int> dp(m + 1);
  for (int i = 0; i < (int)(n); i++) {
    vector<int> ndp = dp;
    for (int j = 1; j <= v[i].size(); j++) {
      for (int k = j; k <= m; k++) {
        chmax(ndp[k], dp[k - j] + v[i][j]);
      }
    }
    swap(dp, ndp);
  }
  cout << dp[m] << '\n';
  return 0;
}

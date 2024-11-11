#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long double PI = 2 * acos(0.0);
const vector<long long int> dx = {1, -1, 0, 0};
const vector<long long int> dy = {0, 0, 1, -1};
template <typename T = long long int>
vector<T> ga(long long int n, bool oneIndexed = false) {
  vector<T> a = vector<T>(n + oneIndexed);
  for (long long int i = 0; i < n; i++) {
    T p;
    cin >> p;
    a[i + oneIndexed] = p;
  }
  return move(a);
}
template <typename T, typename A>
void pa(vector<T, A> const &a, long long int begin = 0,
        long long int end = -1) {
  if (end == -1) end = (long long int)a.size() - 1;
  for (long long int i = begin; i <= end; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
template <typename T, typename A>
void papair(vector<T, A> const &a, long long int begin = 0,
            long long int end = -1) {
  if (end == -1) end = (long long int)a.size() - 1;
  for (long long int i = begin; i <= end; i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> len = ga(m);
  vector<long long int> ans;
  long long int sum = 0, fl = 0;
  for (long long int i = 0; i < m; i++) {
    sum += len[i];
    if (len[i] > n - i) fl = 1;
    ans.push_back(i + 1);
  }
  if (sum < n || fl == 1) {
    cout << "-1";
    return;
  }
  long long int limit = n;
  for (long long int i = m - 1; i >= 0; i--) {
    if (ans[i] + len[i] - 1 < limit) {
      ans[i] = limit - len[i] + 1;
    }
    limit = ans[i] - 1;
  }
  if (ans[0] > 1) {
    cout << "-1";
    return;
  }
  pa(ans);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  solve();
  return 0;
}

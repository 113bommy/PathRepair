#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAX_N = 6e5 + 10;
int n, m, A[MAX_N / 2], F[MAX_N];
ll get_sum(int x) {
  ll ret = 0;
  for (auto i = x; i >= 1; i -= i & -i) ret += F[i];
  return ret;
}
void add(int x, int val) {
  for (auto i = x; i < MAX_N; i += i & -i) F[i] += val;
}
void solve(int TestCase) {
  cin >> n >> m;
  for (auto i = 0; i < m; ++i) cin >> A[i];
  int left = m + 1;
  for (auto i = 0; i < n; ++i) add(left + i, 1);
  map<int, int> M;
  for (auto i = 1; i <= n; ++i) M[i] = left + i - 1;
  auto ret = vector<pair<int, int>>(n + 1);
  for (auto i = 1; i <= n; ++i) ret[i].first = ret[i].second = i;
  for (auto i = 0; i < m; ++i) {
    int q = A[i];
    int x = M[q];
    if (x == left) continue;
    ret[q].second = max((ll)ret[q].second, get_sum(x));
    add(x, -1);
    left--;
    add(left, 1);
    M[q] = left;
    ret[q].first = 1;
  }
  for (auto i = 1; i <= n; ++i)
    ret[i].second = max((ll)ret[i].second, get_sum(M[i]));
  for (auto i = 1; i <= n; ++i)
    cout << ret[i].first << " " << ret[i].second << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (auto i = 1; i <= t; ++i) {
    solve(i);
  }
}

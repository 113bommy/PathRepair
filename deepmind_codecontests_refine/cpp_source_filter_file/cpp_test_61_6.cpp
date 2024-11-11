#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
void solve() {
  int n;
  cin >> n;
  map<int, set<int>> m;
  vector<int> A(n + 1, 0), B(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    m[a].insert(b);
    A[a]++;
    B[b]++;
  }
  i64 count = n * (n - 1) * (n - 2) / 6;
  vector<int> sum(n + 1, 0);
  for (auto& [a, s] : m) {
    for (int b : s) {
      count -= (s.size() - 1) * (B[b] - 1);
    }
  }
  cout << count << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; ++i) solve();
  return 0;
}

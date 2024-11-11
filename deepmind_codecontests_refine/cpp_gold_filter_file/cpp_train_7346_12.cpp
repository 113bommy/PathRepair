#include <bits/stdc++.h>
using namespace std;
using uint64 = uint64_t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> sol;
  for (int i = 1; i <= n; i++) {
    n -= i;
    sol.push_back(i);
  }
  sol.back() += n;
  cout << sol.size() << '\n';
  for (auto i : sol) cout << i << ' ';
  return 0;
}

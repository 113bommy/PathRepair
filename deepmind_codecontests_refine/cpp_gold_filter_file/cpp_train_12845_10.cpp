#include <bits/stdc++.h>
using namespace std;
void solve(int n, int k) {
  int maxK = (n * (n - 1)) / 2;
  if (maxK <= k) {
    cout << "no solution" << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << 0 << " " << i << '\n';
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}

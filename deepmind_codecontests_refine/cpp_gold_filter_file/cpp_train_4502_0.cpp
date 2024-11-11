#include <bits/stdc++.h>
using namespace std;
int rsolve() {
  int value;
  std::cin >> value;
  if (value % 2 == 0) return (value / 2) - 1;
  return value / 2;
}
void solve() {
  int t;
  std::cin >> t;
  for (int casenum = 1; casenum <= t; casenum++) {
    std::cout << rsolve() << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}

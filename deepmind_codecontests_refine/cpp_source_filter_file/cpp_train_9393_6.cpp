#include <bits/stdc++.h>
using namespace std;
const long long MODULO = 1000000007;
void ftime() {}
static int speed_increase = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}();
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "-1\n";
    return;
  }
  int ones = n - 1;
  if ((n - 1) % 3 == 0) {
    ones = n - 2;
  }
  for (int i = 0; i < ones; i++) {
    cout << "1";
  }
  if (n - ones > 1) {
    cout << "2";
  }
  cout << "3\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

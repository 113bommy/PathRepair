#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n;
  cout << 2 << "\n";
  for (int i = 2; i <= n; i++) {
    k = i * (i + 1) * (i + 1) - (i - 1);
    cout << k << "\n";
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

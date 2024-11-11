#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 2 != 0) {
    cout << n << "\n";
    return;
  }
  cout << (n / 2 - 1) << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

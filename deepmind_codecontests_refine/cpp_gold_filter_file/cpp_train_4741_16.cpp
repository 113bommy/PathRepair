#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  cout << 2 * (n / 3) + (n % 3 > 0);
}
int main() {
  solve();
  exit(0);
}

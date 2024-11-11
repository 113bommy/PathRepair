#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 2; i <= n + 1; i++) cout << i << " ";
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

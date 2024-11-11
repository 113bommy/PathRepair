#include <bits/stdc++.h>
using namespace std;
void solve();
const int N = 10000005;
int i, j, n, s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
void solve() {
  cin >> n;
  for (i = 1; i <= n; i = i * 10) {
    s += n - i + 1;
  }
  cout << s;
}

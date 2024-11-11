#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long res[] = {0, 1,         0, 18,        0, 1800,
                     0, 670320,    0, 734832000, 0, 890786230,
                     0, 695720788, 0, 150347555, 0};
  long long n;
  cin >> n;
  cout << res[n - 1];
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}

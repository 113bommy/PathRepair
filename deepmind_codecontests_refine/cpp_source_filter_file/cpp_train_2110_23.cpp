#include <bits/stdc++.h>
using namespace std;
int min3(int a, int b, int c) {
  if (a <= b && a <= c)
    return a;
  else if (b <= a && b <= c)
    return b;
  else
    return c;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

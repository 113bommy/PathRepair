#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int b, mn = 1e4;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i];
  }
  for (int i = 0; i < (int)(n); i++) {
    int s = 0;
    for (int j = 0; j < (int)(a[i]); j++) {
      cin >> b;
      s += b * 5;
    }
    s += a[i] * 15;
    mn = min(s, mn);
  }
  cout << mn << endl;
  cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
  return 0;
}

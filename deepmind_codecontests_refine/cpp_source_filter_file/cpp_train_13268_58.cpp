#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    cin >> q;
    if (p < q) ans++;
  }
  cout << ans << endl;
}

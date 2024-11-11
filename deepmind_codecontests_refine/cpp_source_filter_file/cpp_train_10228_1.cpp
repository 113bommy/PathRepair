#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (b * b <= a && (a + b) % 2 == 0) {
      cout << "YES" << endl;
      continue;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

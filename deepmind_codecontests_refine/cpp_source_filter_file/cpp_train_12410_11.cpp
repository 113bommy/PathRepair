#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k1, k2, a, p1 = 0, p2 = 0;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) {
      cin >> a;
      p1 = max(a, p1);
    }
    for (int i = 0; i < k1; i++) {
      cin >> a;
      p2 = max(a, p2);
    }
    if (p1 > p2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

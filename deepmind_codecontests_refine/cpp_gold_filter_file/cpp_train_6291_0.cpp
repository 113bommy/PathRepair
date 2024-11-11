#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k[101], m, mi = 1000000;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    int c = 0, s = 0;
    for (int j = 0; j < k[i]; j++) {
      cin >> m;
      s += m * 5;
      c++;
    }
    s += c * 15;
    mi = min(s, mi);
  }
  cout << mi;
  return 0;
}

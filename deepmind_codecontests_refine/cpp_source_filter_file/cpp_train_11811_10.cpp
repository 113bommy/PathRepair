#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000000], b, c, x, y, z, s, p;
string st;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      cout << i;
      return 0;
    }
  }
  return 0;
}

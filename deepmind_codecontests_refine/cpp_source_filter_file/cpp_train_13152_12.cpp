#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, t, n, a[4004];
  fill(a + 1, a + 4004, -1000);
  cin >> n;
  for (i = 0; i < 3; i++) {
    cin >> t;
    for (j = t; j <= n; j++) {
      a[j] = max(a[j], a[j - t] + 1);
    }
  }
  cout << a[n] << endl;
  return 0;
}

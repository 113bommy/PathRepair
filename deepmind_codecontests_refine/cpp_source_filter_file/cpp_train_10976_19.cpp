#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, i, c = 0, m, a[2001];
  cin >> k >> n;
  for (i = 0; i < k; i++) cin >> a[i];
  for (i = 0; i < k; i++) a[i] += n;
  for (i = 0; i < k; i++) {
    if (a[i] <= 5) {
      c++;
      if (c == 3) {
        m++;
        c = 0;
      }
    }
  }
  cout << m << "\n";
  return 0;
}

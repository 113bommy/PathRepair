#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, l, j, m = 0, a, b;
  long long int k;
  cin >> n >> a >> b;
  if (b > 0) {
    m = 0;
    for (i = a;; i++) {
      if (m == b) break;
      m++;
      if (i > n) {
        i = 1;
      }
    }
    cout << i;
  } else {
    b = -b;
    m = 0;
    for (i = a;; i--) {
      if (m == b) break;
      m++;
      if (i < 1) {
        i = n;
      }
    }
    cout << i;
  }
}

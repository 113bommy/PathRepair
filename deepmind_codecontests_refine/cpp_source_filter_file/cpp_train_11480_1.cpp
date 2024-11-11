#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, l, m, n, p;
  cin >> p;
  while (p--) {
    cin >> n;
    long long x[n];
    for (i = 0; i < n; i++) cin >> x[i];
    j = 0;
    for (i = 0; i < n; i++) {
      l = x[i];
      while (x[i] > x[i + 1] && i < n) {
        i++;
      }
      j += l - x[i];
    }
    cout << j << endl;
  }
  return 0;
}

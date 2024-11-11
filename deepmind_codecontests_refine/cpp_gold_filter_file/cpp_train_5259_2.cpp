#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, K = 4e2 + 7, inf = 1e9 + 7;
const double eps = 1e-9;
int i, a[N], p[N], k = 1, n, maxk = 1;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (i = 1; i < n; i++) {
    if (p[i + 1] > p[i]) {
      k++;
    } else {
      k = 1;
    }
    maxk = max(k, maxk);
  }
  cout << n - maxk << endl;
}

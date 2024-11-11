#include <bits/stdc++.h>
using namespace std;
const int N = 5000, K = (int)1e5 + 1;
int n, m, k;
int t, p;
int l[N], c[N], x[K];
int main() {
  x[0] = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> t >> p >> x[i];
    p--;
    if (t == 1)
      l[p] = i;
    else
      c[p] = i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << x[max(l[i], c[j])] << " ";
    }
    cout << endl;
  }
  return 0;
}

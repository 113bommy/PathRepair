#include <bits/stdc++.h>
using namespace std;
int inf = 2147483647;
const long long ll = 9223372036854775807, ninf = 1000000000;
const double eps = 1e-6;
const long long nll = 223372036854775807;
int A[100005] = {};
int g[100005] = {};
int f[100005] = {};
int main() {
  int a;
  while (cin >> a) {
    fill(g, g + 100005, inf);
    g[0] = 0;
    for (int i = 1; i <= a; i++) cin >> A[i];
    for (int i = 1; i <= a; i++) {
      int k = lower_bound(g + 1, g + 1 + a, A[i]) - g;
      f[i] = max(f[i - 1], k);
      g[k] = A[i];
    }
    cout << f[a] << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int M = 1005;
const long long mod = 1000000007;
const int inf = (1 << 30);
const long long linf = (1LL << 61);
int n, k, i1, i2, t, l;
struct sol {
  int i, j;
} a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  i1 = 1;
  i2 = 2;
  t = 1;
  cin >> n >> k;
  while (l < n && t < k) {
    ++l;
    a[l].i = i1;
    a[l].j = i2;
    ++l;
    a[l].i = i2;
    a[l].j = i1;
    ++i2;
    if (i2 > k) {
      ++t;
      i1 = t;
      i2 = t + 1;
    }
  }
  if (l != n) {
    cout << "nO";
    return 0;
  }
  cout << "yEs\n";
  for (int i = 1; i <= n; ++i) cout << a[i].i << ' ' << a[i].j << '\n';
  return 0;
}

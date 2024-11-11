#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 101;
long long n, m, l;
long long a[N], h[N];
long long g[N];
long long mx;
int main() {
  cin >> n >> l >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> h[i];
    g[i] = a[i] - a[i - 1] - h[i - 1];
  }
  g[n + 1] = l - a[n] - h[n];
  for (int i = 1; i <= n + 1; ++i) {
    mx += g[i] / m;
  }
  cout << mx;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
int b[N];
long long d[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], ++b[a[i]];
  d[0] = 0;
  d[1] = 1 * b[1];
  for (int i = 2; i <= 1e5; ++i) {
    d[i] = 1ll * i * b[i] + max(d[i - 2], d[i - 3]);
  }
  cout << max(d[100000], d[100000 - 1]);
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007, inf = 2e18;
const int N = 200001;
const double ep = 1e-10;
void Darling(int kase) {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; (1 < 0 && i > n) || (1 > 0 && i < n); i += 1) cin >> a[i];
  for (int i = 0; (1 < 0 && i > n) || (1 > 0 && i < n); i += 1)
    if (a[i] % 2 == i % 2) {
      cout << -1 << '\n';
      return;
    }
  vector<int> z;
  int o = 1;
  while (o < n) {
    int i1 = 0, i2 = 1;
    for (int i = 0; (1 < 0 && i > n) || (1 > 0 && i < n); i += 1) {
      if (a[i] == o) i1 = i;
      if (a[i] == o + 1) i2 = i;
    }
    z.push_back(i1 + 1), reverse(a, a + i1 + 1);
    if (i2 < i1) i2 = i1 - i2;
    i1 = 0;
    z.push_back(i2), reverse(a, a + i2);
    i1 = i2 - 1;
    z.push_back(i2 + 2), reverse(a, a + i2 + 2);
    z.push_back(3), reverse(a, a + 3);
    z.push_back(n - o + 1), reverse(a, a + n - o + 1);
    o += 2;
  }
  cout << z.size() + 1 << '\n';
  for (int x : z) cout << x << ' ';
  cout << n << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  cin >> T;
  for (int K = 0; K < T; K++) Darling(K + 1);
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, j, n, m, first, c = 0;
  vector<long long int> a, b;
  cin >> first;
  if (first == 1) {
    cout << 1 << "\n" << 1 << " " << 1;
    return 0;
  }
  for (n = 1; n * n <= first; ++n) {
    long long int o = 6 * first + n * n * n - n;
    long long int d = 3 * n * (n + 1);
    if (n > o / d) break;
    if (o % d == 0) {
      long long int m = o / d;
      a.push_back(n);
      b.push_back(m);
      if (n == m) ++c;
    }
  }
  cout << 2 * a.size() - c << "\n";
  for (i = 0; i < a.size(); ++i) cout << a[i] << " " << b[i] << "\n";
  for (i = (a.size() - 1) ? a.size() - 1 : 0; i >= 0; --i)
    if (b[i] != a[i]) cout << b[i] << " " << a[i] << "\n";
}

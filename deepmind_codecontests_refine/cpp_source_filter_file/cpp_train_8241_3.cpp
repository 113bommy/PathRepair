#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a;
    if (n >= m)
      a.push_back(m % 10);
    else {
      cout << "0\n";
      continue;
    }
    for (int i = 2 * m; i <= n; i += m) {
      if (i % 10 != a[0])
        a.push_back(i % 10);
      else
        break;
    }
    long long x = (n / m) / (long long)(a.size());
    long long y = (n / m) % (long long)(a.size());
    long long u = 0, v = 0;
    for (int i = 0; i < a.size(); i++) {
      if (i < y) u += a[i];
      v += a[i];
    }
    cout << v * x + u << "\n";
  }
}

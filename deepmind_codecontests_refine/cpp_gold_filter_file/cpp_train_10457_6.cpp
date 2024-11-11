#include <bits/stdc++.h>
using namespace std;
long long n, a, b, i, c[209], s;
string d;
signed main() {
  cin >> n >> a >> b >> d;
  s = d.size();
  if (s < n * a || s > n * b) {
    cout << "No solution";
    return 0;
  } else {
    std::vector<string> v(n + 1);
    for (i = 1; i <= n; i++) c[i] = a;
    s -= (n * a);
    b -= a;
    for (i = 1; i <= n; i++) {
      c[i] += min(s, b);
      s -= min(s, b);
      if (s == 0) break;
    }
    for (i = 1; i <= n; i++) c[i] += c[i - 1];
    for (i = 1; i <= n; i++)
      v[i].assign(d.begin() + c[i - 1], d.begin() + c[i]);
    for (i = 1; i <= n; i++) cout << v[i] << endl;
  }
}

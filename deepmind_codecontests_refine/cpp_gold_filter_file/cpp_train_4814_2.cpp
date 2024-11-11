#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, a, m, s = 0, k = 0, i, t;
  cin >> t;
  while (t--) {
    s = 0;
    k = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a;
      s += a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (s / n >= m)
      cout << n << endl;
    else if (v[0] < m)
      cout << 0 << endl;
    else {
      for (i = 0; i < n;) {
        k += v[i];
        if (k / (i + 1) >= m)
          i++;
        else {
          cout << i << endl;
          break;
        }
      }
    }
  }
  return 0;
}

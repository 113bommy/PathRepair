#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int m, n, c, x, t, l, r, tc, k;
  cin >> tc;
  while (tc--) {
    vector<long long int> v;
    cin >> n >> m;
    k = 0, t = INT_MAX, c = 0;
    while (n--) {
      cin >> l >> r;
      k = max(k, l);
      v.push_back(l - r);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (k >= m) {
      cout << "1\n";
    } else if (v[0] < 0) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
          x = m - k;
          c = x / v[i];
          if (x % v[i] != 0) {
            c++;
          }
          c++;
          t = min(t, c);
        } else {
          break;
        }
      }
      cout << t << endl;
    }
  }
}

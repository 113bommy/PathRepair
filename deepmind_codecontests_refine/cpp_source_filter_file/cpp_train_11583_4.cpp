#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, k, b = 0, c = 0, d = 0, e, i, j, x, y, m, m1, mp, m2, r;
  cin >> t;
  string s;
  for (j = 0; j < t; j++) {
    vector<long long int> v;
    cin >> n >> k;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        v.push_back(i + 1);
      }
    }
    if (v.size() == 0) {
      m1 = ((n - 1) / (k + 1));
      cout << m1 + 1 << endl;
    } else {
      mp = (v[0] - 1);
      r = mp / (k + 1);
      for (i = 1; i < v.size(); i++) {
        if ((v[i] - (v[i - 1] + 1)) >= (k * 2) + 1) {
          m2 = (v[i] - (v[i - 1] + 1));
          c += m2 / ((k + 2));
        }
      }
      m = (n - (v[v.size() - 1]));
      cout << c + (m / (k + 1)) + r << endl;
    }
    c = 0;
    d = 0;
    b = 0;
    x = 0;
    y = 0;
    m = 0;
    m1 = 0;
    mp = 0;
    m2 = 0;
    r = 0;
  }
  return 0;
}

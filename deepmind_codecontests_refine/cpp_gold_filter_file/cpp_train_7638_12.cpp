#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, a, b, c, n, t, m, p, q, d, e, f;
  vector<long long int> v, s, vv;
  map<long long int, long long int> ma, sa;
  map<char, long long int>::iterator it, ki;
  string st, et;
  cin >> n >> m >> d;
  f = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a;
      if (ma[a] == 0) {
        s.push_back(a);
      }
      v.push_back(a);
      ma[a]++;
    }
  }
  if (ma.size() == 1) {
    cout << 0 << endl;
  } else {
    c = 0;
    for (i = 0; i < s.size(); i++) {
      c = 0;
      f = 0;
      for (j = 0; j < v.size(); j++) {
        if (v[j] != s[i] && abs(v[j] - s[i]) % d == 0) {
          c = c + (abs(v[j] - s[i]) / d);
        } else if (v[j] != s[i] && abs(v[j] - s[i]) % d != 0) {
          f = 1;
          break;
        }
      }
      if (f == 0) {
        vv.push_back(c);
      }
    }
    if (vv.size() == 0) {
      cout << -1 << endl;
    } else {
      sort(vv.begin(), vv.end());
      cout << vv[0] << endl;
    }
  }
}

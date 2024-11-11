#include <bits/stdc++.h>
using namespace std;
long long t, n, c, k, l, d;
string s;
char a[100][100];
signed main() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    cin >> s;
    d = 0;
    set<long long> v, r;
    vector<long long> p;
    set<long long>::iterator m, e, g;
    c = 0;
    for (int j = 0; j < n; j++) {
      if (int(s[j]) == 49) {
        v.insert(j + 1);
        c = c + 1;
      } else {
        r.insert(j + 1);
        p.push_back(j + 1);
        d = d + 1;
      }
    }
    if ((n - c) == 0) {
      cout << "YES"
           << "\n";
      for (k = 1; k <= n; k++) {
        for (l = 1; l <= n; l++) {
          if (k == l) {
            cout << "X";
          } else {
            cout << "=";
          }
        }
        cout << "\n";
      }
    } else if ((n - c) <= 2) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      for (k = 1; k <= n; k++) {
        for (l = 1; l <= n; l++) {
          if (k <= p[d - 1] && k >= p[0]) {
            m = r.lower_bound(k);
            if (k == l) {
              cout << "X";
            } else if ((k == p[d - 1]) && (l == p[0])) {
              cout << "+";
            } else if ((k == p[0]) && (l == p[d - 1])) {
              cout << "-";
            } else if (k == (*m)) {
              if (k == p[d - 1]) {
                g = m;
                --g;
                if (l == *g) {
                  cout << "-";
                } else {
                  cout << "=";
                }
              } else if (k == p[0]) {
                if (l == p[1]) {
                  cout << "+";
                } else {
                  cout << "=";
                }
              } else {
                g = m;
                e = m;
                --g;
                ++e;
                if (l == *(g)) {
                  cout << "-";
                } else if (l == *(e)) {
                  cout << "+";
                } else {
                  cout << "=";
                }
              }
            } else {
              cout << "=";
            }
          } else {
            if (k == l) {
              cout << "X";
            } else {
              cout << "=";
            }
          }
        }
        cout << "\n";
      }
    }
  }
}

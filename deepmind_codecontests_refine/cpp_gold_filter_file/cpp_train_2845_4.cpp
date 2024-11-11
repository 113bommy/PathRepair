#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)(t.size()))); ++(i)) s << t[i] << " ";
  return s;
}
int d[100010];
int main() {
  int n, m;
  cin >> n >> m;
  string sign;
  int q;
  bool fail;
  int wit;
  for (int(i) = 0; (i) < (n); ++(i)) {
    d[i] = 0;
  }
  for (int(i) = 0; (i) < (m); ++(i)) {
    cin >> sign >> q;
    fail = false;
    wit = -1;
    if (sign[0] == '+') {
      if (d[q] == q) {
        cout << "Already on" << endl;
      } else {
        if (d[q] != 0) {
          fail = true;
          wit = d[q];
        } else {
          for (int k = 2; k * k <= q && !fail; k++) {
            if (q % k == 0) {
              if (d[k] != 0) {
                fail = true;
                wit = d[k];
              } else if (d[q / k] != 0) {
                fail = true;
                wit = d[q / k];
              }
            }
          }
        }
        if (!fail) {
          for (int k = 2; k * k <= q; k++) {
            if (q % k == 0) {
              d[k] = q;
              d[q / k] = q;
            }
          }
          d[q] = q;
          cout << "Success" << endl;
        } else {
          cout << "Conflict with " << wit << endl;
        }
      }
    } else {
      if (d[q] != q) {
        cout << "Already off" << endl;
      } else {
        for (int k = 2; k * k <= q; k++) {
          if (q % k == 0) {
            d[k] = 0;
            d[q / k] = 0;
          }
        }
        d[q] = 0;
        cout << "Success" << endl;
      }
    }
  }
  return 0;
}

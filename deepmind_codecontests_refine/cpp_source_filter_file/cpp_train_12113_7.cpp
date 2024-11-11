#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cerr << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cerr << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cerr << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cerr << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int main() {
  int x, t, a, b, da, db;
  while (cin >> x >> t >> a >> b >> da >> db) {
    if (x == 0) {
      cout << "YES" << endl;
      continue;
    }
    int found = 0;
    int h = b;
    for (int j = 0; j < t - 1; j++) {
      h = b;
      for (int i = 0; i < t - 1; i++) {
        if (a + h == x || a == x || h == x) {
          cout << "YES" << endl;
          found = 1;
          break;
        }
        h -= db;
      }
      a -= da;
      if (found) break;
    }
    if (!found) cout << "NO" << endl;
  }
}

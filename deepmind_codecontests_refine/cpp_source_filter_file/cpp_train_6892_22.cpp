#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, vector<T> t) {
  s << "{";
  for (int i = 0; i < t.size(); i++)
    s << t[i] << (i == t.size() - 1 ? "" : ",");
  return s << "}" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t1, t2, t0, x1, x2;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  t1 -= t0;
  t2 -= t0;
  if (t1 == 0 && t2 == 0) {
    cout << x1 << " " << x2;
    return 0;
  } else if (t1 == 0 && t2 > 0) {
    cout << x1 << " " << 0;
    return 0;
  } else if (t1 < 0 && t2 > 0) {
    t1 = abs(t1);
    long long b = 10000000000000LL, b1 = 0, b2 = 1;
    for (int i = 1; i <= x2; i++) {
      long long g = i * t2;
      long long n1 = g / t1;
      if (n1 > x1) continue;
      long long n2 = i;
      if ((n1 + n2) * (-b1 * t1 + b2 * t2) >=
          (b1 + b2) * (-n1 * t1 + n2 * t2)) {
        if ((n1 + n2) * (-b1 * t1 + b2 * t2) >
            (b1 + b2) * (-n1 * t1 + n2 * t2)) {
          b1 = n1;
          b2 = n2;
        } else if (b1 + b2 < n1 + n2) {
          b1 = n1;
          b2 = n2;
        }
      }
    }
    cout << b1 << " " << b2;
    return 0;
  } else {
    cout << 0 << " " << x2;
  }
  return 0;
}

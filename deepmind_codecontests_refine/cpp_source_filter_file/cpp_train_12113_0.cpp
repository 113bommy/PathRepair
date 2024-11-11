#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T sqr(const T &a) {
  return a * a;
}
template <typename T>
inline int nread(vector<T> &a) {
  int n;
  cin >> n;
  a.clear();
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  return n;
}
int main() {
  int x, t, a, b, da, db;
  cin >> x >> t >> a >> b >> da >> db;
  for (int t1 = -1; t1 <= t; t1++)
    for (int t2 = -1; t2 <= t; t2++) {
      int gain = 0;
      if (t1 != -1) gain += a - da * t1;
      if (t2 != -1) gain += b - db * t2;
      if (gain == x) {
        cout << "YES" << endl;
        return 0;
      }
    }
  cout << "NO" << endl;
  return 0;
}

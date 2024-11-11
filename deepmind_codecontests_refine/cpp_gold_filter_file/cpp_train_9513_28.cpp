#include <bits/stdc++.h>
using namespace std;
template <class T>
inline string tostring(T n) {
  stringstream ss;
  ss << n;
  ss.flush();
  return ss.str();
}
template <class T>
inline string tobinary(T n) {
  string s = n ? "" : "0";
  while (n) {
    s += ((n & 1) + '0');
    n >>= 1;
  }
  return s;
}
template <class T>
inline int digits(T n) {
  int cnt = n ? 0 : 1;
  while (n) {
    n /= 10;
    cnt++;
  }
  return cnt;
}
template <class T1, class T2>
inline T2 gcd(T1 a, T2 b) {
  return !b ? a : gcd(b, a % b);
}
template <class T>
inline T abs(T a) {
  return a < 0 ? -a : a;
}
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3) {
    if (n == 3) {
      printf("%d %d\n%d %d\n%d %d\n", 0, 0, 0, 1, 1, 0);
    } else if (n == 4) {
      printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, 2, 0, 2, 3, 1, 1);
    } else {
      puts("-1");
    }
    return 0;
  }
  int i;
  for (i = 1; i <= m; i++) {
    cout << i << " " << 1000000 + i * i << endl;
  }
  for (i = m + 1; i <= n; i++) {
    cout << i << " " << -1000000 - i * i << endl;
  }
  return 0;
}

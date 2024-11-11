#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int main() {
  long long int n, l, r, mid, pos, ans, ret, rem, i, j, k;
  while (scanf("%lld", &n) == 1) {
    l = 0, r = 1000000000;
    while (l <= r) {
      mid = (l + r) / 2;
      ret = mid * (mid + 1);
      ret /= 2;
      if (ret < n) {
        pos = ret;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    rem = n - pos;
    ans = 0;
    while (rem--) ans++;
    printf("%lld\n", ans);
  }
  return 0;
}

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
bool flag;
long long bigmod(long long base, long long power) {
  if (power == 0) return 1;
  if (power == 1) return base;
  if (power & 1)
    return ((base % 1000000007) * (bigmod(base, power - 1) % 1000000007)) %
           1000000007;
  else {
    long long ret = bigmod(base, power / 2) % 1000000007;
    return (ret * ret) % 1000000007;
  }
}
int main() {
  long long n;
  while (cin >> n) {
    if (n == 0) {
      cout << 1 << endl;
      continue;
    }
    long long ret1 =
        ((2 % 1000000007) * (bigmod(4, n - 1) % 1000000007)) % 1000000007;
    long long ret2 = bigmod(2, n - 1);
    long long ans = (ret1 % 1000000007 + ret2 % 1000000007) % 1000000007;
    cout << ans << endl;
  }
  return 0;
}

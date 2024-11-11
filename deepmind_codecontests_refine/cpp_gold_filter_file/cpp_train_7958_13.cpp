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
void check_time() {}
const int res = 1e5 + 5;
const long long int mod = 1e9 + 7;
int n, m, sum, total, ans, digit;
int main() {
  scanf("%d", &n);
  if (n <= 3) {
    deb("NO");
    return 0;
  }
  deb("YES");
  if (n & 1) {
    deb("5 + 1 = 6");
    deb("6 * 4 = 24");
    deb("3 - 2 = 1");
    deb("24 * 1 = 24");
    for (int i = 6; i < n; i += 2) {
      cout << i + 1 << " - " << i << " = "
           << "1" << endl;
      deb("24 * 1 = 24");
    }
  } else {
    deb("1 * 2 = 2");
    deb("2 * 3 = 6");
    deb("6 * 4 = 24");
    for (int i = 5; i < n; i += 2) {
      cout << i + 1 << " - " << i << " = "
           << "1" << endl;
      deb("24 * 1 = 24");
    }
  }
  return 0;
}

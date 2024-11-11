#include <bits/stdc++.h>
using namespace std;
const int LIM = 600;
bool prime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
struct triple {
  int a, b, c;
  triple() : a(0), b(0), c(0) {}
  bool operator!=(const triple& it) {
    return a != it.a || b != it.b || c != it.c;
  }
};
pair<int, int> pempty = pair<int, int>(0, 0);
triple tempty = triple();
vector<pair<int, int>> vp(LIM, pempty);
vector<triple> vt(LIM);
int main() {
  int n;
  for (n = 3; n < LIM; ++n) {
    for (int i = 2; n - i >= 2; ++i) {
      if (prime(i) && prime(n - i)) {
        vp[n].first = i;
        vp[n].second = n - i;
      }
    }
    for (int i = 2; i <= n; ++i)
      for (int j = 2; n - i - j >= 2; ++j)
        if (prime(i) && prime(j) && prime(n - i - j)) {
          vt[n].a = i;
          vt[n].b = j;
          vt[n].c = n - i - j;
        }
  }
  cin >> n;
  if (prime(n)) {
    cout << 1 << endl << n << endl;
    return 0;
  } else if (n < LIM) {
    if (vp[n] != pempty) {
      cout << 2 << endl << vp[n].first << " " << vp[n].second << endl;
      return 0;
    } else if (vt[n] != tempty) {
      cout << 3 << endl << vt[n].a << " " << vt[n].b << " " << vt[n].c << endl;
      return 0;
    }
  } else {
    for (int m = 2; n - m >= 2 && m < LIM; ++m) {
      if (prime(m) && prime(n - m)) {
        cout << 2 << endl << m << " " << n - m << endl;
        return 0;
      } else if (vp[m] != pempty && prime(n - m)) {
        cout << 3 << endl
             << n - m << " " << vp[m].first << " " << vp[m].second << endl;
        return 0;
      }
    }
  }
  return 0;
}

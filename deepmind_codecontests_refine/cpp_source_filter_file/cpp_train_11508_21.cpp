#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
template <typename t1>
t1 gcd(t1 a, t1 b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename t1>
t1 lcm(t1 a, t1 b) {
  return a * (b / gcd(a, b));
}
int main() {
  int n, d, h;
  while (cin >> n >> d >> h) {
    if (h == 1 && d == 1 && n > 2)
      cout << -1 << endl;
    else if (d < h)
      cout << -1 << endl;
    else if (n <= d || d < 2 * h)
      cout << -1 << endl;
    else if (h == d) {
      {
        int l = h;
        int now = 1;
        while (l--) {
          cout << now << " " << now + 1 << endl;
          now++;
        }
        now++;
        int nnn = 2;
        int tem = d + 1;
        while (now <= n) {
          cout << nnn << " " << now++ << endl;
        }
      }
    } else {
      int l = h;
      int now = 1;
      while (l--) {
        cout << now << " " << now + 1 << endl;
        now++;
      }
      now++;
      int rem = d - h;
      while (now <= n) {
        int flag = 0;
        int noww = 1;
        int nrem = rem;
        while (nrem--) {
          if (now > n) {
            flag = 1;
            break;
          }
          cout << noww << " " << now << endl;
          noww = now;
          now++;
        }
        if (flag) break;
      }
    }
  }
}

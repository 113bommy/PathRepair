#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
bool f[3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a = 0, b = 0, ret, ret1, ret2;
  cout << "? 0 0" << endl;
  cin >> ret;
  f[1 - ret] = 1;
  for (int i = 29; i >= 0; i--) {
    int tmp1 = (1 << i), tmp2 = (0 << i);
    if (ret == 1) {
      cout << "? " << (a ^ tmp1) << " " << (b ^ tmp2) << endl;
      cin >> ret1;
      cout << "? " << (a ^ tmp2) << " " << (b ^ tmp1) << endl;
      cin >> ret2;
      if (ret1 == 0) {
        ret = 0;
        a ^= tmp1;
        b ^= tmp2;
      } else if (ret1 == -1) {
        if (ret2 == 1) {
          a ^= tmp1;
          b ^= tmp1;
        } else if (ret2 == -1) {
          ret = -1;
          a ^= tmp1;
          b ^= tmp2;
        }
      } else if (ret1 == 1) {
        if (ret2 == 1) {
          a ^= tmp1;
          b ^= tmp2;
          ret = 1;
        } else if (ret2 == -1) {
          a ^= tmp2;
          b ^= tmp2;
        }
      }
    } else if (ret == 0) {
      cout << "?" << (a ^ tmp1) << " " << (b ^ tmp2) << endl;
      cin >> ret1;
      if (ret1 == 1) {
        a ^= tmp2;
        b ^= tmp2;
      } else if (ret1 == -1) {
        a ^= tmp1;
        b ^= tmp1;
      }
    } else if (ret == -1) {
      cout << "?" << (a ^ tmp1) << " " << (b ^ tmp2) << endl;
      cin >> ret1;
      cout << "?" << (a ^ tmp2) << " " << (b ^ tmp1) << endl;
      cin >> ret2;
      if (ret1 == 0) {
        ret = 0;
        a ^= tmp2;
        b ^= tmp1;
      } else if (ret1 == -1) {
        if (ret2 == 1) {
          a ^= tmp1;
          b ^= tmp1;
        } else if (ret2 == -1) {
          ret = -1;
          a ^= tmp2;
          b ^= tmp1;
        }
      } else if (ret1 == 1) {
        if (ret2 == 1) {
          a ^= tmp2;
          b ^= tmp1;
          ret = 1;
        } else if (ret2 == -1) {
          a ^= tmp2;
          b ^= tmp2;
        }
      }
    }
  }
  cout << "! " << a << " " << b << endl;
  return 0;
}

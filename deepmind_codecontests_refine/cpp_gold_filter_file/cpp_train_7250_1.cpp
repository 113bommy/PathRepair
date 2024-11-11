#include <bits/stdc++.h>
template <typename T>
inline void SWAP(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
template <typename T>
inline T ABS(const T &val) {
  return val < 0 ? -val : val;
}
template <typename T>
inline T MAX(const T &a, const T &b) {
  return a > b ? a : b;
}
template <typename T>
inline T MIN(const T &a, const T &b) {
  return a < b ? a : b;
}
const int INTinf = 2147483647;
const int nINTinf = 0 - 2147483648;
using namespace std;
int n;
struct pt {
  int val, first, second, mul;
  pt() {}
};
pt mass[27];
pt answ[27];
int mnsteps = 7;
void rec(int pos) {
  if (pos == mnsteps) return;
  for (int i = 0; i != pos; i++) {
    mass[pos].second = i;
    for (int x = 1; x <= 3; x++) {
      mass[pos].val = mass[i].val << x;
      mass[pos].mul = x;
      if (mass[pos].val == n) {
        mnsteps = pos;
        for (int l = 0; l != pos + 1; l++) {
          answ[l] = mass[l];
        }
        return;
      } else if (mass[pos].val < n) {
        rec(pos + 1);
      } else
        break;
    }
    for (int j = 0; j != pos; j++) {
      mass[pos].first = j;
      for (int x = 0; x != 4; x++) {
        mass[pos].val = mass[j].val + (mass[i].val << x);
        mass[pos].mul = x;
        if (mass[pos].val == n) {
          mnsteps = pos;
          for (int l = 0; l != pos + 1; l++) {
            answ[l] = mass[l];
          }
          return;
        } else if (mass[pos].val < n) {
          rec(pos + 1);
        } else
          break;
      }
    }
    mass[pos].first = -1;
  }
}
int table[] = {1, 2, 4, 8};
char answM[8][50];
int main() {
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i != 28; i++) {
    mass[i].first = -1;
    mass[i].second = -1;
  }
  mass[0].val = 1;
  rec(1);
  cout << mnsteps << endl;
  for (int i = mnsteps; i != 0; i--) {
    if (answ[i].first != -1) {
      sprintf(answM[i - 1], "lea e%cx, [e%cx + %d*e%cx]", 'a' + i,
              'a' + answ[i].first, table[answ[i].mul], 'a' + answ[i].second);
    } else {
      sprintf(answM[i - 1], "lea e%cx, [%d*e%cx]", 'a' + i, table[answ[i].mul],
              'a' + answ[i].second);
    }
  }
  for (int i = 0; i != mnsteps; i++) {
    cout << answM[i] << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long t, ten[17], n, maxval, res, curr, s, len;
bool isbit(long long it, long long n) {
  it = 1 << it;
  return n & it;
}
int main() {
  cin >> t;
  ten[0] = 1;
  for (int i = 1; i <= 11; i++) ten[i] = ten[i - 1] * 10;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= 10; i++) {
      if (n / ten[i] == 0) {
        len = i - 1;
        break;
      }
    }
    maxval = (1 << 9) - 1;
    res = 0;
    for (int i = 0; i <= maxval; i++) {
      curr = 1;
      for (int j = 0; j < 9; j++) {
        s = (n / ten[j]) % 10;
        if (isbit(j, i) && j + 2 > len) {
          curr = 0;
          break;
        }
        if (j > 1) {
          if (isbit(j - 2, i)) s--;
          if (s < 0 && !isbit(j, i)) {
            curr = 0;
            break;
          }
          if (s < 0) s += 10;
          if (s == 9 && isbit(j, i) && !isbit(j - 2, i)) {
            curr = 0;
            break;
          }
          if (s == 9) {
            curr *= 10;
            continue;
          }
          if (!isbit(j, i))
            curr *= s + 1;
          else
            curr *= 9 - s;
        } else {
          if (s == 9 && isbit(j, i)) {
            curr = 0;
            break;
          }
          if (s == 9) {
            curr *= 10;
            continue;
          }
          if (!isbit(j, i))
            curr *= s + 1;
          else
            curr *= 9 - s;
        }
      }
      res += curr;
    }
    cout << res - 2 << endl;
  }
  return 0;
}

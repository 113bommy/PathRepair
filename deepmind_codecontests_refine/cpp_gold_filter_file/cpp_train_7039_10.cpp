#include <bits/stdc++.h>
using namespace std;
long long gen(int order) {
  long long sum = 0;
  while (order != 0) {
    sum = (sum * 10) + 9;
    order--;
  }
  return sum;
}
int main() {
  long long l, r;
  cin >> l >> r;
  long long p = l, k = r;
  int order = 0, sorder = 0;
  while (k != 0) {
    k = k / 10;
    order++;
  }
  while (p != 0) {
    p = p / 10;
    sorder++;
  }
  if (sorder == order) {
    long long max = gen(order);
    if ((max - 1) / 2 <= r && l <= (max - 1) / 2) {
      long long ans = ((max + 1) / 2) * ((max - 1) / 2);
      cout << ans;
    } else {
      long long max = gen(order);
      if (r < (max - 1) / 2) {
        long long ans = r * (max - r);
        cout << ans;
      } else {
        long long ans = l * (max - l);
        cout << ans;
      }
    }
  } else {
    long long max = gen(order);
    long long smax = gen(order - 1);
    if (r >= (max - 1) / 2) {
      long long ans = ((max + 1) / 2) * ((max - 1) / 2);
      cout << ans;
    } else {
      if (l <= (smax + 1) / 2) {
        if ((smax + 1) * (smax - 1) / 4 > r * (max - r)) {
          cout << (smax + 1) * (smax - 1) / 4;
        } else {
          cout << r * (max - r);
        }
      } else {
        if (l * (smax - l) > r * (max - r)) {
          cout << l * (smax - l);
        } else {
          cout << r * (max - r);
        }
      }
    }
  }
}

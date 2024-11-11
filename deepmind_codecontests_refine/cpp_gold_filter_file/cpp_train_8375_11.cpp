#include <bits/stdc++.h>
using namespace std;
struct sample {
  long long a;
  long long b;
};
pair<long long, pair<long long, long long> > extendedEuclid(long long a,
                                                            long long b) {
  long long x = 1, y = 0;
  long long xLast = 0, yLast = 1;
  long long q, r, m, n;
  while (a != 0) {
    q = b / a;
    r = b % a;
    m = xLast - q * x;
    n = yLast - q * y;
    xLast = x, yLast = y;
    x = m, y = n;
    b = a, a = r;
  }
  return make_pair(b, make_pair(xLast, yLast));
}
long long modInverse(long long a, long long m) {
  return (extendedEuclid(a, m).second.first + m) % m;
}
bool digits(long long n) {
  n = abs(n);
  while (n != 0) {
    if (n % 10 == 8) return true;
    n = n / 10;
  }
  return false;
}
int gcd(int x, int y) {
  if (x % y == 0) return y;
  return gcd(y, x % y);
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long l, r;
    cin >> l >> r;
    if (l == r) {
      cout << l << endl;
      continue;
    }
    vector<long long> arrl(70);
    vector<long long> arrr(70);
    int i_l = 69;
    while (l != 0) {
      arrl[i_l] = l % 2;
      l = l / 2;
      i_l--;
    }
    int i_r = 69;
    while (r != 0) {
      arrr[i_r] = r % 2;
      r = r / 2;
      i_r--;
    }
    int index = 69;
    for (int i = 0; i < 70; i++) {
      if (arrl[i] == arrr[i])
        continue;
      else {
        index = i;
        break;
      }
    }
    for (int i = index + 1; i < 70; i++) {
      arrl[i] = 1;
    }
    long long mul = 1;
    long long x = 0, y = 0;
    int num_x = 0, num_y = 0;
    for (int i = 69; i >= 0; i--) {
      x += arrr[i] * mul;
      if (arrr[i] == 1) num_x++;
      y += arrl[i] * mul;
      if (arrl[i] == 1) num_y++;
      mul *= 2;
    }
    if (num_x > num_y)
      cout << x << endl;
    else
      cout << y << endl;
  }
}

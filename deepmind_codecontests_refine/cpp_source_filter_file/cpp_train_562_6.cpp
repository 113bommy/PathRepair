#include <bits/stdc++.h>
using namespace std;
long long a, b, oo = 1ll << 50;
int main() {
  cin >> a >> b;
  if (a == 0) {
    cout << -b * b << endl;
    for (int(i) = 0; i < int(b); ++i) printf("x");
    puts("");
    return 0;
  }
  if (b < 2) {
    cout << a * a - b << endl;
    if (b) printf("x");
    for (int(i) = 0; i < int(a); ++i) printf("o");
    puts("");
    return 0;
  }
  long long res = -oo;
  int div = -1;
  if (a * a - b * b > res) {
    res = a * a - b * b;
    div = 1;
  }
  if (a * a - (b / 2) * (b / 2) - ((b + 1) / 2) * ((b + 1) / 2) > res) {
    res = a * a - (b / 2) * (b / 2) - ((b + 1) / 2) * ((b + 1) / 2);
    div = 2;
  }
  for (int i = 3; i <= b; ++i) {
    if (i - 1 > a) break;
    long long small = b / i;
    long long large = b / i + 1;
    long long lc = b % i;
    long long sc = i - lc;
    long long cur = -(sc * small * small + lc * large * large);
    cur += i - 2;
    cur += (a - (i - 2)) * (a - (i - 2));
    if (cur > res) {
      res = cur;
      div = i;
    }
  }
  cout << res << endl;
  if (div == 1) {
    for (int(i) = 0; i < int(a); ++i) printf("o");
    for (int(i) = 0; i < int(b); ++i) printf("x");
    puts("");
  } else if (div == 2) {
    for (int(i) = 0; i < int(b / 2); ++i) printf("x");
    for (int(i) = 0; i < int(a); ++i) printf("o");
    for (int(i) = 0; i < int((b % 2) + b / 2); ++i) printf("x");
    puts("");
  } else {
    long long small = b / div;
    long long large = b / div + 1;
    long long lc = b % div;
    long long sc = div - lc;
    bool turn = true;
    while (sc) {
      if (turn) {
        int print = large;
        if (lc)
          --lc;
        else {
          print = small;
          --sc;
        }
        for (int(i) = 0; i < int(print); ++i) printf("x");
      } else {
        if (sc == 1)
          for (int(i) = 0; i < int(a); ++i) printf("o");
        else {
          --a;
          printf("o");
        }
      }
      turn = !turn;
    }
    puts("");
  }
  cin >> a;
}

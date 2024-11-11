#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k, l, c, d, p, nl, np;
  float dr, sl, toast, salt;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  dr = k * l;
  sl = c * d;
  toast = dr / nl;
  salt = p / np;
  int min = 0;
  if (toast / n <= salt / n && toast / n <= sl / n) {
    min = toast / n;
  } else if (salt / n <= toast / n && salt / n <= sl / n) {
    min = salt / n;
  } else {
    min = sl / n;
  }
  cout << min;
  return 0;
}

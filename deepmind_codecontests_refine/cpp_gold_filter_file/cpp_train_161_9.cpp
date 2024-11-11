#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, su = 0;
  int a;
  cin >> n;
  if (n == 0)
    su = 1;
  else
    while (n > 0) {
      a = n % 16;
      n /= 16;
      if (a == 0 || a == 4 || a == 6 || a == 9 || a == 10 || a == 13) su++;
      if (a == 8 || a == 11) su += 2;
    }
  cout << su;
  return 0;
}

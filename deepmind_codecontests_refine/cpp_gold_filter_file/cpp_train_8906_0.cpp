#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long res = 0;
  long long x = 2, y = 1;
  while (x <= n) {
    long long xx = x;
    x += y;
    y = xx;
    res++;
  }
  cout << res;
  return 0;
}

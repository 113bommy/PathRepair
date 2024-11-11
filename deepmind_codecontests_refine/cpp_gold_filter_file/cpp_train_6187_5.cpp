#include <bits/stdc++.h>
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ax = n, bx = 0;
  n *= n;
  int res = 0;
  while (true) {
    bx++;
    if (ax * ax + bx * bx > n) {
      ax--;
    }
    if (ax <= bx) {
      break;
    }
    res++;
  }
  bool bo = false;
  if (n == 0) {
    cout << 1;
    return 0;
  }
  if (ax == bx && ax * ax + bx * bx <= n) bo = true;
  cout << 8ll * res + 4ll + (bo ? 4ll : 0ll) << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long int fast_expo(long long int x, long long int p) {
  if (p == 0)
    return 1;
  else if (p % 2 == 0) {
    long long int t = fast_expo(x, p / 2) % 100000;
    return (t * t) % 100000;
  } else
    return (x * (fast_expo(x, p - 1)) % 100000) % 100000;
}
int main() {
  int n;
  cin >> n;
  int dup = n, cnt = 0;
  while (dup) {
    int r = dup % 10;
    if (cnt == 0) {
      n -= r;
      n += r * 100;
    }
    if (cnt == 2) {
      n -= r * 100;
      n += r * 1000;
    }
    if (cnt == 3) {
      n += r;
      n -= r * 1000;
    }
    cnt++;
    dup /= 10;
  }
  long long int val = fast_expo(n, 5);
  int val1 = val;
  cnt = 0;
  while (val) {
    val /= 10;
    cnt++;
  }
  if (val1 == 0) cnt = 1;
  for (int i = 0; i < 5 - cnt; i++) cout << 0;
  cout << val1;
}

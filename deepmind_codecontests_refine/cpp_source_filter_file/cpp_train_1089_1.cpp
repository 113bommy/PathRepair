#include <bits/stdc++.h>
using namespace std;
unsigned long long travel(unsigned long long h, unsigned long long n,
                          unsigned long long t) {
  unsigned long long tot;
  if (h == 0) return 0;
  tot = 1 << h;
  if (t == 0) {
    if (n <= tot / 2)
      return travel(h - 1, n, 1) + 1;
    else
      return tot + travel(h - 1, n - tot / 2, 0);
  } else {
    if (n <= tot / 2)
      return tot + travel(h - 1, n, 1);
    else
      return travel(h - 1, n - tot / 2, 0) + 1;
  }
}
int main() {
  unsigned long long h;
  unsigned long long n, res;
  cin >> h >> n;
  cout << travel(h, n, 0);
  return 0;
}

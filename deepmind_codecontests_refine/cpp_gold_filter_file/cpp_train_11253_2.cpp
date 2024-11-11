#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int main() {
  cin >> n;
  l = n - sqrt(n) + 1;
  r = n;
  while (1) {
    for (int i = l; i <= r; ++i) cout << i << " ";
    if (l == 1) break;
    r -= sqrt(n);
    if (r <= 0) {
      r = l - 1;
      l = 1;
      continue;
    }
    l -= sqrt(n);
    l = max(1, l);
  }
  return 0;
}

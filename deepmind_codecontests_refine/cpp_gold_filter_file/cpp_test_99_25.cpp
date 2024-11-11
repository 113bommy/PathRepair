#include <bits/stdc++.h>
using namespace std;
int q;
long long x, n, tmp;
int main() {
  cin >> q;
  while (q--) {
    cin >> x >> n;
    tmp = n % 4;
    n -= tmp;
    if (tmp == 0) {
      cout << x << "\n";
      continue;
    }
    if (x % 2 != 0) {
      x += n + 1;
      for (int i = 2; i <= tmp; i++) x -= n + i;
    } else {
      x -= n + 1;
      for (int i = 2; i <= tmp; i++) x += n + i;
    }
    cout << x << "\n";
  }
  return 0;
}

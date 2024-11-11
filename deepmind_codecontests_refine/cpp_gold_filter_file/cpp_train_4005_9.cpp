#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    unsigned long long a, b;
    cin >> a >> b;
    if (a == b) {
      cout << a << endl;
      continue;
    }
    if (!a) a++;
    if (!b) b++;
    int a1 = 64 - __builtin_clzll(a);
    int b1 = 64 - __builtin_clzll(b);
    if (!((b + 1) & (~(1LL << b1)))) {
      cout << b << endl;
      continue;
    }
    if (a1 != b1)
      cout << (1LL << (b1 - 1)) - 1 << endl;
    else {
      unsigned long long ans = 0;
      for (int x = b1 - 1; x >= 0; x--) {
        if ((b & (1LL << x)) && !(a & (1LL << x))) {
          for (int y = x - 1; y >= 0; y--) ans += (1LL << y);
          break;
        } else
          ans += ((b & (1LL << x)) ? (1LL << x) : 0);
      }
      cout << (__builtin_popcountll(b) > __builtin_popcountll(ans) ? b : ans)
           << endl;
    }
  }
}

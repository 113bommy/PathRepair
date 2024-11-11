#include <bits/stdc++.h>
using namespace std;
long long int solve(long long int h, long long int n, int op) {
  if (h == 0LL) return 0LL;
  long long int ret = 0LL;
  if (op == 1) {
    if (n > (1LL << (h - 1LL))) {
      ret += (1LL << h);
      n -= (1LL << (h - 1LL));
      return ret + solve(h - 1LL, n, 1);
    } else {
      ret += 1LL;
      return ret + solve(h - 1LL, n, 0);
    }
  } else {
    if (n > (1LL << (h - 1LL))) {
      ret += 1LL;
      n -= (1LL << (h - 1LL));
      return ret + solve(h - 1LL, n, 1);
    } else {
      ret += (1LL << h);
      return ret + solve(h - 1LL, n, 0);
    }
  }
}
int main() {
  long long int h, n;
  while (cin >> h >> n) {
    cout << solve(h, n, 1) << endl;
  }
  return 0;
}

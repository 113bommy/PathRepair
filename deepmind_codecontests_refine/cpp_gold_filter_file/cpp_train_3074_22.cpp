#include <bits/stdc++.h>
using namespace std;
long long x, s;
int main() {
  cin >> s >> x;
  long long d = s - x;
  if (d < 0 || d & 1 || (d >> 1) & x) {
    cout << 0;
    return 0;
  }
  long long res = (1LL << (__builtin_popcountll(x)));
  if (d == 0) res -= 2;
  cout << res;
  return 0;
}

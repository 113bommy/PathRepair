#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, x;
  cin >> s >> x;
  long long a = (s - x) / 2;
  if (a < 0 || ((s - x) & 1) || (a & x) != 0) {
    cout << 0;
    return 0;
  }
  long long res = 1;
  for (long long y = x; y; y /= 2) res *= (y & 1 ? 2 : 1);
  if (s == x) res -= 2;
  cout << res;
}

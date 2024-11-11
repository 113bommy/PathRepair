#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 63 - 1;
int n, x;
int xo = 0;
int main() {
  cin >> n >> x;
  if (n == 2 && x == 0) return cout << "NO", 0;
  cout << "YES" << endl;
  for (int i = (1 << 18); i > (1 << 18) - n + 1; i--) {
    if (i == (1 << 18) - n + 2 && (xo ^ i ^ x) == (1 << 18)) i--;
    xo ^= i;
    printf("%d\n", i);
  }
  xo ^= x;
  cout << xo << endl;
  return 0;
}

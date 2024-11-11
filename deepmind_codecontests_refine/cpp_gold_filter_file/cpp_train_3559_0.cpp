#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, ans = -1;
  cin >> n >> p;
  for (int i = 1; i < 33; i++) {
    if (n - i * p < i) continue;
    if (__builtin_popcount(n - i * p) > i) continue;
    ans = i;
    break;
  }
  cout << ans << endl;
}

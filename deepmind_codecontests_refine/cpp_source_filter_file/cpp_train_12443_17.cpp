#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long s, first;
  cin >> s >> first;
  if (s < first) {
    cout << 0;
    return 0;
  }
  long long d = s - first;
  int l = 0;
  while (d > 0) {
    if (d & 1ll) {
      if (!(l - 1 >= 0 && ((1ll << (l - 1)) & first) == 0)) {
        cout << 0;
        return 0;
      }
    }
    d >>= 1;
    l++;
  }
  cout << ((1ll << __builtin_popcount(first)) - (s - first == 0ll) * 2);
  return 0;
}

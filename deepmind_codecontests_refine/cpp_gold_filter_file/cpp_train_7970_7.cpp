#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int n, k, tim = 0, t = 0, cnt, i = 1;
  cin >> n >> k;
  t = 240 - k;
  for (i = 1; i <= n; i++) {
    tim = tim + (5 * i);
    if (tim > t) {
      cnt = i;
      break;
    }
  }
  cout << i - 1;
  return 0;
}

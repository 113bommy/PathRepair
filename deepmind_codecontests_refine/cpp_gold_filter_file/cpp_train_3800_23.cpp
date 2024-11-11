#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 10;
int main() {
  int n, x;
  cin >> n >> x;
  int cnt = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0 && x / i <= n && i <= n) {
      if (x / i == i)
        ++cnt;
      else
        cnt += 2;
    }
  }
  cout << cnt;
  return 0;
}

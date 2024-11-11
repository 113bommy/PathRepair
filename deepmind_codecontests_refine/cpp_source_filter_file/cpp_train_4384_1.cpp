#include <bits/stdc++.h>
using namespace std;
int main() {
  long long w, h, k;
  cin >> w >> h >> k;
  long long ans = 0;
  for (long long i = 0; i < k; i++) {
    ans = ans + 2 * w + 2 * h - 4;
    w = w - 2;
    h = h - 2;
  }
  cout << ans;
}

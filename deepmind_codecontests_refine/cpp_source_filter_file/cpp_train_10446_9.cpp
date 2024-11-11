#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w, h;
  cin >> w >> h;
  long long int i = 2;
  long long int ans = 0;
  for (long long int i = 2; i <= w; i += 2) {
    for (long long int j = 2; j <= h; j += 2) {
      ans += (h - i + 1) * (w - j + 1);
    }
  }
  cout << ans;
  return 0;
}

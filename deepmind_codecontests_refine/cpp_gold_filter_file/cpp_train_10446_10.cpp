#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int w, h;
  cin >> w >> h;
  long long int ans = 0;
  for (long long int i = 0; i <= w; i++)
    for (long long int j = 0; j <= h; j++) {
      long long int per = min(i, w - i);
      long long int cur = min(j, h - j);
      ans = ans + per * cur;
    }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, p, w, d, c, x, y, flag = 0;
  cin >> n >> p >> w >> d;
  for (int i = 0; i < w; i++) {
    c = p - i * w;
    if (c >= 0 && c % w == 0) {
      x = c / w;
      if (n - (x + i) >= 0) {
        cout << x << " " << i << " " << n - (x + i) << "\n";
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) cout << -1;
}

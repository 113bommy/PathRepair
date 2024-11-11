#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    cin >> n;
    int ws = 0, minx = 100;
    int nn = n, top;
    while (nn) {
      if (nn < 10) top = nn;
      nn /= 10;
      ws++;
    }
    int temp = 1;
    for (int i = 0; i < ws - 1; i++) {
      temp = temp * 10 + 1;
    }
    int res = (ws - 1) * 9 + (top - 1) + (temp <= n ? 1 : 0);
    cout << res << endl;
  }
  return 0;
}

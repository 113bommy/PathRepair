#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 55;
int ans[MAX_SIZE];
int main(void) {
  int T;
  cin >> T;
  while (T--) {
    memset(ans, 0, sizeof(ans));
    int n, x, y;
    cin >> n >> x >> y;
    int temp = y - x;
    if (temp % (n - 2 + 1) == 0) {
      int d = temp / (n - 2 + 1);
      int st = x;
      cout << x << " ";
      for (int i = 2; i <= n; i++) {
        cout << x + d << " ";
        x += d;
      }
      cout << endl;
    } else {
      int node = n;
      while (temp % (node - 2 + 1)) {
        node--;
      }
      int d = temp / (node - 2 + 1);
      int temp1 = n - node;
      int now = x;
      if (now > 0) {
        while (now > 0 && temp1) {
          temp1--;
          now -= d;
        }
        if (now <= 0) now += d;
      }
      for (int i = 1; i <= n; i++) {
        cout << now << " ";
        now += d;
      }
      cout << endl;
    }
  }
  return 0;
}

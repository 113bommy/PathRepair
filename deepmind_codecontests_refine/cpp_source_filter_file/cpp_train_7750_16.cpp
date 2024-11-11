#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  int max = 0;
  int flag = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    int amount = x * 100 + y;
    if (amount < (s * 100)) {
      flag = 1;
      int total = ((s * 100) - amount);
      int change = total % 100;
      if (change > max) {
        max = change;
      }
    }
  }
  if (flag == 0) {
    cout << -1 << endl;
  } else {
    cout << max << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int d[20];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> d[i];
    int up = (1 << n), flag = 0;
    for (int i = 0; i < up; i++) {
      int tp = 0;
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i)
          tp += d[j];
        else
          tp -= d[j];
      }
      if (tp % 360 == 0) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int d[1000002];
  int n;
  cin >> n;
  int x, y;
  for (int iji = 0; iji < n; iji++) {
    scanf("%d %d", &x, &y);
    int t = trunc(sqrt(x));
    int num = 0;
    for (int i = 1; i <= t; i++) {
      if ((x % i) != 0) {
        continue;
      } else {
        int d1, d2;
        d1 = i;
        d2 = x / i;
        if ((iji - d[d1] + 1) > y) {
          num++;
        }
        if ((iji - d[d2] + 1) > y) {
          num++;
          if (d2 == d1) {
            num--;
          }
        }
        d[d1] = iji + 1;
        d[d2] = iji + 1;
      }
    }
    int d1 = x;
    if ((iji - d[d1] + 1) > y) {
      num++;
    }
    d[d1] = iji + 1;
    cout << num << endl;
  }
}

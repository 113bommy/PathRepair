#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long d;
    cin >> d;
    long long dis = d * d - 4 * d;
    if (dis < 0) {
      cout << "N\n";
      continue;
    } else {
      double sq = sqrt(dis);
      double b = (d + sq) / 2.0;
      if (b == 1) {
        cout << "N\n";
        continue;
      } else
        printf("Y %.9f %.9f\n", abs(b), abs(b / (b - 1)));
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
struct node {
  double a[1009];
  double b[1009];
};
int op(double st, double en) {
  if (st > en)
    return -1;
  else
    return 1;
}
int main() {
  double minn = 1e12;
  int n, m;
  double wi, st, en = 1e9, mid;
  en += 1000;
  double eps = 0.00000001;
  int i;
  int z = 0;
  cin >> n >> m;
  st = m;
  node c;
  for (i = 0; i < n; i++) cin >> c.a[i];
  for (i = 0; i < n; i++) cin >> c.b[i];
  while (op(st, en) == 1 && (en - st) >= eps) {
    mid = (st + en) / 2;
    wi = mid;
    for (i = 0; i < n; i++) {
      if (i == 0) {
        wi -= (wi / c.a[i]);
      } else {
        wi -= (wi / c.b[i]);
        wi -= (wi / c.a[i]);
      }
      if (wi < m) break;
    }
    wi -= (wi / c.b[0]);
    if (wi >= m) {
      minn = min(minn, mid - m);
      en = mid;
    } else {
      st = mid;
    }
  }
  if (minn == 1e12) {
    cout << "-1";
  } else
    printf("%.11f", minn);
  return 0;
}

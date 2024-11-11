#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    int a = 0, b = 0, *p = new int[300005], *q = new int[300005], flag = 0;
    int max = 0, min = 100000, maxi, mini;
    for (int i = 0; i < n; i++) {
      cin >> *(p + i) >> *(q + i);
      if (*(p + i) >= max) {
        max = *(p + i);
        maxi = i;
      }
      if (*(q + i) <= min) {
        min = *(q + i);
        mini = i;
      }
    }
    if (*(p + mini) == max || *(q + maxi) == min) flag = 1;
    if (n > 2) {
      sort(p, p + n);
      sort(q, q + n);
    }
    int l1 = *(p + n - 1), l2 = *(p + n - 2), r1 = *(q), r2 = *(q + 1);
    if (flag && n > 2)
      cout << r2 - l2 << endl;
    else {
      if (r2 - l1 > 0 || r1 - l2 > 0) {
        int k = r2 - l1, l = r1 - l2;
        if (k > l)
          cout << k;
        else
          cout << l;
        cout << endl;
      } else
        cout << 0 << endl;
    }
  }
  return 0;
}

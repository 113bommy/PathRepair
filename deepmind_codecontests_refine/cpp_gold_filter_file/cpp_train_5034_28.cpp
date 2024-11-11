#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  long long n;
  long long res;
  while (cin >> n) {
    res = 0;
    bool iszero = false;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      res += a[i];
      iszero |= a[i];
    }
    if (!iszero) {
      res = (n - 1) * (n - 2) / 2;
      cout << res << endl;
    } else {
      int l[100005];
      memset(l, 0, sizeof(l));
      long long tem = 0, tp = 0;
      if (res % 3 == 0) {
        l[0] = 0;
        for (int i = 0; i < n; i++) {
          tem += a[i];
          if (tem == res / 3) {
            l[i + 1] = l[i] + 1;
          } else {
            l[i + 1] = l[i];
          }
        }
        tem = 0;
        for (int k = n - 1; k > 0; k--) {
          tem += a[k];
          if (tem == res / 3) {
            tp += l[k - 1];
          }
        }
        cout << tp << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}

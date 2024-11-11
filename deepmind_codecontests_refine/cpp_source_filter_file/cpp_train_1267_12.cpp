#include <bits/stdc++.h>
using namespace std;
long long a[100050];
long long n, x, y, d;
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= 10; i++) a[i] = 0x3f3f3f3f;
  for (int i = n + 11; i <= n + 21; i++) a[i] = 0x3f3f3f3f;
  for (int i = 11; i <= 10 + n; i++) cin >> a[i];
  for (int i = 11; a[i]; i++) {
    int cnt = 0, flag = 0;
    for (int j = i - 1; j >= 1; j++) {
      if (a[j] >= a[i]) cnt++;
      if (cnt >= x) break;
      if (a[j] < a[i]) {
        cnt = 0;
        break;
      }
    }
    if (cnt >= x) {
      int cnt = 0;
      for (int j = i + 1; a[j]; j++) {
        if (a[j] >= a[i]) cnt++;
        if (cnt >= y) break;
        if (a[j] < a[i]) break;
      }
      if (cnt >= y) {
        d = i;
        flag = 1;
      }
    }
    if (flag == 1) break;
  }
  cout << d - 10 << endl;
  return 0;
}

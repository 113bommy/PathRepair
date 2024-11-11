#include <bits/stdc++.h>
long long MOD = 1e9 + 7;
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[600010];
  bool F = false;
  for (int i = 0; i < n; i++) cin >> a[i];
  int g = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) F = true;
    if (a[i] < 0) g++;
    if (a[i] == 0) zero++;
  }
  int pre = 2 * 1e9;
  int pre2 = 2 * 1e9;
  if (zero && g % 2) {
    bool flag = true;
    int M = -2 * 1e9;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) M = max(M, a[i]);
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == M && flag) {
        if (pre2 != 2 * 1e9) {
          printf("%d %d %d\n", 1, pre2, i + 1);
          pre2 = i + 1;
        } else
          pre2 = i + 1;
        flag = false;
      } else if (a[i] == 0) {
        if (pre2 != 2 * 1e9) {
          printf("%d %d %d\n", 1, pre2, i + 1);
          pre2 = i + 1;
        } else
          pre2 = i + 1;
      } else {
        if (pre != 2 * 1e9) {
          printf("%d %d %d\n", 1, pre, i + 1);
          pre = i + 1;
        } else
          pre = i + 1;
      }
    }
    if (F || g > 1) printf("%d %d", 2, pre2);
    return 0;
  }
  if (zero && g % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        if (pre2 != 2 * 1e9) {
          printf("%d %d %d\n", 1, pre2, i + 1);
          pre2 = i + 1;
        } else
          pre2 = i + 1;
      } else {
        if (pre != 2 * 1e9) {
          printf("%d %d %d\n", 1, pre, i + 1);
          pre = i + 1;
        } else
          pre = i + 1;
      }
    }
    if (F || g > 1) printf("%d %d", 2, pre2);
    return 0;
  }
  if (g % 2) {
    int M = -2 * 1e9;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0) M = max(M, a[i]);
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == M && flag) {
        cout << 2 << " " << i + 1 << endl;
        flag = false;
      } else {
        if (pre != 2 * 1e9) {
          printf("%d %d %d\n", 1, pre, i + 1);
          pre = i + 1;
        } else
          pre = i + 1;
      }
    }
    return 0;
  }
  if (g % 2 == 0) {
    int M = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) M = min(M, a[i]);
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (pre != 2 * 1e9) {
        printf("%d %d %d\n", 1, pre, i + 1);
        pre = i + 1;
      } else
        pre = i + 1;
    }
    return 0;
  }
}

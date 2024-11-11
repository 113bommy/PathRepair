#include <bits/stdc++.h>
using namespace std;
char a[1010];
int main() {
  int n, l, r;
  for (int i = 0;; i++) {
    cin >> a[i];
    if (a[i] == '=') {
      l = i;
      break;
    }
  }
  cin >> n;
  int q = 0, w = 0;
  for (int i = 0; i <= l; i++) {
    if (a[i] == '-') q++;
    if (a[i] == '+') w++;
  }
  if (q > n * w or n * q + n <= w) {
    printf("Impossible");
    return 0;
  } else
    printf("Possible\n");
  if (q > w) {
    for (int i = 0; i <= l; i++) {
      if (i == 0) {
        int t = n + q - n * w;
        r = 0;
        if (t < 1) t = 1, r = abs(n + q - n * w - 1);
        cout << t << " ";
        continue;
      }
      if (a[i] != '?') cout << a[i] << " ";
      if (a[i - 1] == '-') {
        int e;
        e = r + 1;
        r = 0;
        if (e > n) r = e - n, e = n;
        cout << e << " ";
      }
      if (a[i - 1] == '+') cout << n << " ";
    }
    cout << n;
  }
  if (q < w) {
    for (int i = 0; i <= l; i++) {
      if (i == 0) {
        int t = n * q + n - w;
        r = 0;
        if (t > n) t = n, r = n * q - w;
        cout << t << " ";
        continue;
      }
      if (a[i] != '?') cout << a[i] << " ";
      if (a[i] == ' ') cout << a[i] << " ";
      if (a[i - 1] == '-') cout << n << " ";
      if (a[i - 1] == '+') {
        int e;
        e = r + 1;
        r = 0;
        if (e > n) r = e - n, e = n;
        cout << e << " ";
      }
    }
    cout << n;
  }
  if (q == w) {
    for (int i = 0; i <= l; i++) {
      if (i == 0) cout << n << " ";
      if (a[i] != '?') cout << a[i] << " ";
      if (a[i - 1] == '-') cout << 1 << " ";
      if (a[i - 1] == '+') cout << 1 << " ";
    }
    cout << n;
  }
}

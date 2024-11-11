#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[200001], k, t, s[200001], d;
  bool p, l;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  l = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) {
      k = i;
      l = 1;
    }
    s[i] = 0;
  }
  int i = 1;
  int j = 1;
  t = 0;
  while (j <= n) {
    while (s[j] != 0 && j <= n) {
      j++;
    }
    p = 0;
    i = j;
    while (p == 0 && j <= n) {
      s[i] = j;
      i = a[i];
      if (s[i] != 0) {
        p = 1;
        if (s[i] == j || s[i] != k) {
          t++;
          if (l == 0) {
            l = 1;
            a[i] = i;
            k = i;
          } else
            a[i] = k;
        }
      }
    }
  }
  cout << t << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

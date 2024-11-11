#include <bits/stdc++.h>
using namespace std;
char a[101];
int s, p, l, m, k, x, d, g, h, t, y, q;
int main() {
  cin >> a;
  for (int i = 0; a[i] != '\0'; i++) {
    if (a[i] > 96 && a[i] < 123) s++;
    if (a[i] > 64 && a[i] < 91) p++;
  }
  for (int i = 0; a[i] != '\0'; i++) {
    if (s >= p) {
      if (a[i] > 64 && a[i] < 91) a[i] = a[i] + 32;
    } else {
      if (a[i] > 96 && a[i] < 123) a[i] = a[i] - 32;
    }
    cout << a[i];
  }
}

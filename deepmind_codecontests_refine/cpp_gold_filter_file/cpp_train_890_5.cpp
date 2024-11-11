#include <bits/stdc++.h>
using namespace std;
int s[10005] = {0};
int main() {
  int n, m, k, a, b, c = 0, h = 0;
  cin >> n >> m >> k;
  a = max(n, m);
  b = min(n, m);
  n = a;
  m = b;
  if (n == m) {
    cout << k / m << endl;
  } else {
    int i = 1;
    h = n;
    while (h <= k) {
      s[h] = h;
      h = (i * n);
      i++;
    }
    i = 1;
    h = m;
    while (h <= k) {
      if (s[h] == h) {
        c++;
      }
      h = i * m;
      i++;
    }
    cout << c << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, n, k;
  cin >> n;
  int v[n + 1];
  for (int i = 1; i <= n; i++) cin >> v[i];
  int a = 1;
  int b = 1;
  p = 1;
  k = n;
  bool vi;
  bool f;
  if (n == 1) {
    cout << 1 << " " << 0;
  } else {
    while (true) {
      vi = false;
      f = false;
      v[p]--;
      if (v[p] <= 0) {
        p++;
        a++;
        f = true;
      }
      v[k]--;
      if (v[k] <= 0) {
        k--;
        b++;
        vi = true;
      }
      if (vi && f && k == p) {
        b--;
        break;
      } else {
        if (vi && f && k < p) {
          a--;
          b--;
        }
      }
      if (k == p && f) {
        a--;
        break;
      } else if (k == p && vi) {
        b--;
        break;
      }
      if (k == p) break;
      if (k < p) break;
    }
    cout << a << " " << b;
  }
  return 0;
}

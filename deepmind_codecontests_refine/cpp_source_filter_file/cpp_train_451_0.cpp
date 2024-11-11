#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p = 0, r, s = 0, u, o, z;
  cin >> n;
  int l[n];
  int ri[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> ri[i];
  }
  for (int i = 0; i < n; i++) {
    if (l[i] == 0) {
      s++;
    }
    if (ri[i] == 0) {
      p++;
    }
  }
  u = n - s;
  r = n - p;
  if (u >= s)
    o = s;
  else
    o = u;
  if (r >= p) {
    int z = p;
  } else
    z = r;
  cout << z + o;
  return 0;
}

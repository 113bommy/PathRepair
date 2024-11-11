#include <bits/stdc++.h>
using namespace std;
int s[105], t[105];
int main() {
  int n, q;
  cin >> n >> q;
  while (q--) {
    int a, b, c, x = 0;
    cin >> a >> b >> c;
    for (int i = 1; i <= n; ++i)
      if (t[i] <= a) s[++x] = i;
    if (b > x)
      cout << -1 << endl;
    else {
      int suma = 0;
      for (int i = 1; i <= b; ++i) {
        t[s[i]] = c + a;
        suma += s[i];
      }
      cout << suma << endl;
    }
  }
  return 0;
}

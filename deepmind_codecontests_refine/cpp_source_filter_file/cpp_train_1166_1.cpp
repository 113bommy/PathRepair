#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, k;
  cin >> a >> b >> c >> d >> e >> f;
  for (int i = min(a, d); i >= 0; i--)
    k = max(k, i * e + min(b, min(c, d - i)) * f);
  cout << k;
}

#include <bits/stdc++.h>
using namespace std;
int f[50], a, b, c;
int main() {
  cin >> a >> b >> c;
  f[0] = a, f[1] = b;
  for (int i = 2; i <= c; i++) f[i] = f[i - 1] + f[i - 1];
  cout << f[c];
  return 0;
}

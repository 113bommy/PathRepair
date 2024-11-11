#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int c[3];
  c[0] = n * a;
  c[1] = (n / m) * b + (n % m) * a;
  c[2] = (n / m) * b;
  if (n % m) c[2] += m;
  sort(c, c + 3);
  cout << c[0];
  return 0;
}

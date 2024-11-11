#include <bits/stdc++.h>
using namespace std;
int main() {
  double k, n, p, s;
  double x;
  cin >> k >> n >> s >> p;
  x = ceil((n / s)) * k;
  x = ceil(x / p);
  cout << x;
  return 0;
}

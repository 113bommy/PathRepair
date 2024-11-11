#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  int p = 0;
  if (a < c) p = ceil((double(a - c) * w + b) / (x - w));
  cout << p;
}

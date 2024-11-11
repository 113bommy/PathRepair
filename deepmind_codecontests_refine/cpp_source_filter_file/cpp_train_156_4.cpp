#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, x[100005], i;
  cin >> a >> b;
  for (i = 1; i <= a; i++) {
    cin >> x[i];
  }
  c = 0;
  d = 0;
  while (c <= b) {
    d++;
    c = c + d;
  }
  c = c - d;
  e = b - c;
  if (e == 0) e = a;
  cout << x[e] << "\n";
}

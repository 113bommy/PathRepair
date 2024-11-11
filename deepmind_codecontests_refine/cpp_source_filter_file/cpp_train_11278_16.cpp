#include <bits/stdc++.h>
using namespace std;
int r[10000];
int main() {
  int a, b, m, p, count = 0;
  cin >> a >> b >> m >> p;
  while (r[p] == 0) {
    r[p] = ++count;
    p = ((a * p) + b) % m;
  }
  cout << count - r[p] + 1 << endl;
  return 0;
}

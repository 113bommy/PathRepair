#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int a, b, c, d, n, m;
  int q[3];
  b = 0;
  cin >> q[0] >> q[1] >> q[2] >> a;
  sort(q, q + 3);
  if (q[2] - q[1] < a) b = a - (q[2] - q[1]);
  if (q[1] - q[0] < a) b = b + a - (q[1] - q[0]);
  cout << b << endl;
}

#include <bits/stdc++.h>
using namespace std;
int p = 1000001;
void check(int x1, int y1, int x2, int y2, int a, int b) {
  int n = abs(x1 - x2);
  int m = abs(y1 - y2);
  if (n % a == 0 && m % b == 0) {
    if ((n / a - m / b) % 2 == 0) p = min(max(n / a, m / b), p);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, a, b;
  vector<int> v;
  cin >> n >> m >> i >> j >> a >> b;
  check(1, m, i, j, a, b);
  check(n, n, i, j, a, b);
  check(n, m, i, j, a, b);
  check(1, 1, i, j, a, b);
  if (p == 1000001 || (p != 0 && (n <= a || m <= b)))
    cout << "Poor Inna and pony!";
  else
    cout << p;
  return 0;
}

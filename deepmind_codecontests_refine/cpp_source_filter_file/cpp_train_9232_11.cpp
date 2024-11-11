#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void Solve(int a) { return; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double n, vb, vs, ost = 1e8, index, tec;
  cin >> n >> vb >> vs;
  vector<double> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long x, y;
  cin >> x >> y;
  for (int i = 1; i < n; i++) {
    tec = sqrt((x - a[i]) * (x - a[i]) + y * y) / vs + a[i] / vb;
    if (ost > tec) {
      ost = tec;
      index = i;
    }
  }
  cout << index + 1 << "\n";
  return 0;
}

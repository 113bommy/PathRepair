#include <bits/stdc++.h>
using namespace std;
int ceil(int a, int b) { return a / b + (a % b ? (a % b > 0 ? 1 : -1) : 0); }
int dr(int a, int b) {
  int t = a % b;
  return t ? t : a;
}
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  cout << (long long)ceil(n, c) * ceil(m, c) * dr(n, c) * dr(m, c) << endl;
  return 0;
}

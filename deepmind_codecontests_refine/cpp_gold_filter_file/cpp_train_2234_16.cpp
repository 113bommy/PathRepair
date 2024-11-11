#include <bits/stdc++.h>
using namespace std;
map<long long, int> a;
struct niki {
  int x, y;
};
int main() {
  long long z, n, m, i, j, p, ost;
  string s;
  double c = 0;
  bool;
  niki q;
  vector<int> od, dv, tr;
  cin >> n >> m;
  if (n < m) {
    cout << -1;
    return 0;
  }
  if (m == n) {
    cout << n;
    return 0;
  }
  if (n % 2 == 0) {
    z = n / 2;
    p = 0;
  } else {
    z = n / 2;
    p = 1;
  }
  if (p == 0) {
    while (z % m > 0) z++;
    cout << z;
  } else {
    while ((z + 1) % m > 0) z++;
    cout << z + 1;
  }
  return 0;
}

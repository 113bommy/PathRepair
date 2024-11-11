#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (auto &e : v) {
    cin >> e;
    e = abs(e - x);
  }
  int r = v.front();
  for (auto e : v) {
    r = gcd(r, e);
  }
  cout << r << endl;
}

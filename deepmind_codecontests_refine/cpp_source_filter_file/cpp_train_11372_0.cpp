#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int u, v, x;
  cin >> u >> v;
  if (u > v || u % 2 != v % 2) {
    cout << "-1\n";
    return 0;
  }
  if (!v) {
    cout << "0\n";
    return 0;
  }
  if (u == v) {
    cout << "1\n" << u << "\n";
    return 0;
  }
  x = (v - u) / 2;
  if (u & x) {
    cout << "3\n" << u << " " << x << " " << x << "\n";
    return 0;
  }
  cout << "2\n" << u + x << " " << x << "\n";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long u, v;
  cin >> u >> v;
  if (u > v) {
    cout << "-1";
    return 0;
  }
  if ((v - u) % 2 == 1) {
    cout << "-1";
    return 0;
  }
  if (u == v && v == 0) {
    cout << '0';
    return 0;
  }
  if (u == v) {
    cout << '1' << '\n' << u;
    return 0;
  }
  int x = (v - u) / 2;
  if ((x & u) == 0) {
    cout << '2' << '\n' << u + x << ' ' << x;
    return 0;
  } else {
    cout << '3' << '\n' << u << ' ' << x << ' ' << x;
    return 0;
  }
  return 0;
}

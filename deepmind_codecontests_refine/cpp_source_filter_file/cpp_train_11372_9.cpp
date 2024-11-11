#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int u, v;
  cin >> u >> v;
  if ((u % 2 != v % 2) || (u > v)) {
    cout << "-1" << endl;
  } else if (u == v) {
    if (u == 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
      cout << u << endl;
    }
  } else {
    long int x = (v - u) / 2;
    if (x & u) {
      cout << 3 << endl;
      cout << u << " "
           << " " << x << " " << x << endl;
    } else {
      cout << 2 << endl;
      cout << (u ^ x) << " " << x << endl;
    }
  }
}

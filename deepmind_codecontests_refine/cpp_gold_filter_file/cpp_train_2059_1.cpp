#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if (abs(a - b) <= t*(v - w)) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
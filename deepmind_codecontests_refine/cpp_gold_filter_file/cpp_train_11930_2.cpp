#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, k, d;
  while (cin >> n >> t >> k >> d) {
    if (d < ((n - 1) / k) * t)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

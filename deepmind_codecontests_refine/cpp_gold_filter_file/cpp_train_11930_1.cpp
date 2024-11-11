#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, t, k, d;
  cin >> n >> t >> k >> d;
  double firstOven = ceil(n / k) * t;
  if (d + t < firstOven) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}

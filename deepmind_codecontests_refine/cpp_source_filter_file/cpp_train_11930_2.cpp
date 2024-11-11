#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, t, k, d;
  cin >> n >> t >> k >> d;
  double firstOven = (n * t) / k;
  if (d + t < firstOven) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}

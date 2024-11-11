#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  cin >> n;
  for (int i = 0; i >= 0; i++) {
    double t = i * (i + 1) / 2;
    if (t > n) break;
    if (t == n) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}

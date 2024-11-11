#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << 1440 - ((a * 60) + b);
  }
}

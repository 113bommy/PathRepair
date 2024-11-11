#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << 2400 - (60 * a + b) << "\n";
  }
  return 0;
}

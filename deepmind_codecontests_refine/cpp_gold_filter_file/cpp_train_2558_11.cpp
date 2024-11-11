#include <bits/stdc++.h>
using namespace std;
int n;
int max = 1000000009;
int main() {
  cout << "YES" << endl;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a % 2;
    int y = b % 2;
    x = (x + 2) % 2;
    y = (y + 2) % 2;
    cout << 1 + x + 2 * y << endl;
  }
  return 0;
}

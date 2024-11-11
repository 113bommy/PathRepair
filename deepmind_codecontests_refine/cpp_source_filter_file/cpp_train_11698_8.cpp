#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d[3] = {0}, a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    d[a] = b - c;
  }
  cout << ((d[1] >= 0) ? "LIVE" : "DEAD") << endl;
  cout << ((d[2] >= 0) ? "LIVE" : "DEAD") << endl;
  return 0;
}

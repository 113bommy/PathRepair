#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, r;
  cin >> n >> x >> y;
  r = (n * y + 99) / 100;
  cout << max(0, r - x) << endl;
}

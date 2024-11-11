#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  double n, x, y;
  cin >> n >> x >> y;
  cout << (int)(ceil(((n * y) / 100) - x));
}

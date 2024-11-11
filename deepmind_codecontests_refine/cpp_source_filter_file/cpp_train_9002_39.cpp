#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int MAX = 100000000;
int n, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x, y, x1, y1, n, k = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> x1 >> y1;
    k += (x1 - x) * (y1 - y);
  }
  cout << k;
}

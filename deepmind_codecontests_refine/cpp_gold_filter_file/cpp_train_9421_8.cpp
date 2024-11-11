#include <bits/stdc++.h>
using namespace std;
const double EPS = 1E-9;
int x, y, n;
bool a[100], b[100];
int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> x >> y;
    if (!a[x] && !b[y]) {
      a[x] = b[y] = true;
      cout << i + 1 << " ";
    }
  }
  return 0;
}

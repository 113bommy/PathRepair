#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 7;
const double eps = 1e-9;
const int ALP = 26;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  for (int i = (a + b) / n + 1; i > 0; i--) {
    if (a / i + b / i >= n && a / i > 0 && b / i > 0) {
      cout << i << endl;
      return 0;
    }
  }
}

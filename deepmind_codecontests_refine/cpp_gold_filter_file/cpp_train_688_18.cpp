#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592;
const int inf = (int)1.01e9;
const double eps = (1e-9);
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int a = 0, b = 1, c = 1;
  vector<int> v(1001, 0);
  v[0] = 1;
  v[1] = 1;
  for (int i = 1; i <= n; i++) {
    c = a + b;
    if (c >= 1000) break;
    v[c] = 1;
    a = b;
    b = c;
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] == 1) {
      cout << "O";
    } else {
      cout << "o";
    }
  }
  return 0;
}

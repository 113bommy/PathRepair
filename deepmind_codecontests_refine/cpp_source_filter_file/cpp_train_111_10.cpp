#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, x, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m = max(m, x);
    s += x;
  }
  cout << max(m, (s * 2 - 1) / n + 1) << endl;
}

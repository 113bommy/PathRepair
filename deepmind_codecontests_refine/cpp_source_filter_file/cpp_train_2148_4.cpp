#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 200001, m = 0, l = 0, k = 0, a = 0;
  vector<int> buf(n, 0);
  cin >> m;
  m++;
  for (int i = 1; i < m; i++) {
    cin >> l;
    buf[l] = i;
  }
  for (int i = 1; i < n; i++) {
    if (buf[i] > 0) {
      l = m - buf[i];
      if (l > k) {
        k = l;
        a = i;
      }
    }
  }
  cout << a;
}

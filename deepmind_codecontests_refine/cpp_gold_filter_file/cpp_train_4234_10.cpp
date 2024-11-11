#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
  }
  if (n == m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

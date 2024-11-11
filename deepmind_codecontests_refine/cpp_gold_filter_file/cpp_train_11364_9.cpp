#include <bits/stdc++.h>
using namespace std;
int n, a, m = 1e9;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    m = min(m, a / max(i, n - 1 - i));
  }
  cout << m;
  return 0;
}

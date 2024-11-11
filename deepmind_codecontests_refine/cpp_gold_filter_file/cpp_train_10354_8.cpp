#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, m = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    m = max(m, c);
  }
  cout << m;
  return 0;
}

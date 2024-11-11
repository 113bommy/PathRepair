#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n > m) swap(m, n);
  long long cc = 0;
  for (int i = 1; i <= n; i++) {
    cc += (m + i) / 5 - i / 5;
  }
  cout << cc << endl;
  return 0;
}

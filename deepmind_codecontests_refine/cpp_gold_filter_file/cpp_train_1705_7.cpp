#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> m >> n;
  int c = min(n, m);
  cout << c + 1 << '\n';
  for (int i = 0; i <= c; i++) cout << i << ' ' << n - i << '\n';
  return 0;
}

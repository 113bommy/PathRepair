#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x = n / m, y = n - x * m;
  for (int i = 0; i < m - y; i++) cout << x << " ";
  for (int i = m - y; i < n; i++) cout << x + 1 << " ";
}

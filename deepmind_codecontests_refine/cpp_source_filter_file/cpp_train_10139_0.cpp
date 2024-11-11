#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x = n / m, y = n - x * m;
  for (int i = 0; i < n - y; i++) cout << x << " ";
  for (int i = n - y; i < n; i++) cout << x + 1 << " ";
}

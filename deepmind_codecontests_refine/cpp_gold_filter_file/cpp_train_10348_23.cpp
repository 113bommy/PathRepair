#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  cout << n + m - 1 << endl;
  for (int i = 1; i < m + 1; i++) cout << 1 << " " << i << endl;
  for (int i = 2; i < n + 1; i++) cout << i << " " << 1 << endl;
  return 0;
}

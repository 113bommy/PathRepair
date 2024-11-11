#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 3 && m > 4)
    cout << -1 << endl;
  else {
    for (int i = 0; i < n; i++) cout << i << " " << 1000000 + i * i << endl;
    for (int i = 0; i < m - n; i++)
      cout << i << " " << -1000000 - i * i << endl;
  }
  return 0;
}

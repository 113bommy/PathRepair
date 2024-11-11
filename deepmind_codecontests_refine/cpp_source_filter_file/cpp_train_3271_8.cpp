#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, f;
  cin >> n >> m >> k;
  f = m * (m + 1) / 2;
  cout << f << "\n";
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++)
      if (!k)
        cout << i << " " << j << "\n";
      else
        cout << j << " " << i << "\n";
  return 0;
}

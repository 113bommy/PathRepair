#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if ((i * i + j == n) && (i + j * j == m)) cnt++;
  cout << cnt << endl;
}

#include <bits/stdc++.h>
using namespace std;
int n;
int g[200][200];
int main() {
  cin >> n;
  int k = 1;
  while (k * (k - 1) <= n * 2) ++k;
  for (int i = 1, l = 0; i < k; ++i)
    for (int j = i + 1; j < k; ++j) g[i][j] = g[j][i] = ++l;
  cout << k - 1 << endl;
  for (int i = 1; i < k; ++i, puts(""))
    for (int j = 1; j < k; ++j)
      if (i != j) cout << g[i][j] << " ";
  return 0;
}

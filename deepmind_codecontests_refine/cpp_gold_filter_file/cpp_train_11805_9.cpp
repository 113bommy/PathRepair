#include <bits/stdc++.h>
const int nmax = 1e5 + 5;
int v1[nmax], v2[nmax];
int main() {
  int n, m, k, c;
  std::cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) std::cin >> v1[i];
  for (int j = 1; j <= m; j++) std::cin >> v2[j];
  std::sort(v1 + 1, v1 + n + 1);
  std::sort(v2 + 1, v2 + m + 1);
  int i = n, j = m;
  bool ok = false;
  while (i and j) {
    if (v1[i] > v2[j]) ok = true;
    i--, j--;
  }
  std::cout << ((ok == true or i) ? "YES" : "NO");
}

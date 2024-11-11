#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 1) {
    puts("YES\n1");
    return 0;
  }
  if ((n == 1 && m <= 3) || (m == 1 && n <= 3) || (n == 2 && m <= 3) ||
      (m == 2 && n <= 3)) {
    puts("NO");
    return 0;
  }
  if (n == 1 && m == 4) {
    puts("YES\n2 4 1 3");
    return 0;
  }
  if (n == 4 && m == 1) {
    puts("YES\n2\n4\n1\n3");
    return 0;
  }
  if (n == 1 && m >= 5) {
    puts("YES");
    for (int i = 1; i <= m; i += 2) printf("%d ", i);
    for (int i = 2; i <= m; i += 2) printf("%d ", i);
    return 0;
  }
  if (n >= 5 && m == 1) {
    puts("YES");
    for (int i = 1; i <= n; i += 2) printf("%d\n", i);
    for (int i = 2; i <= n; i += 2) printf("%d\n", i);
    return 0;
  }
  if (n == m && n == 3) {
    puts("YES\n6 1 8\n7 5 3\n2 9 4");
    return 0;
  }
  vector<vector<int> > g;
  g.resize(n);
  for (int i = 0, u = 1; i < n; i++) {
    g[i].resize(m);
    for (int j = 0; j < m; j++) g[i][j] = u++;
  }
  if (n <= m) {
    for (int i = 0; i < n; i++)
      if (i & 1) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) tmp.push_back(g[i][(j + 2) % m]);
        tmp.swap(g[i]);
      }
    for (int j = 0; j < m; j++)
      if (j & 1) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) tmp.push_back(g[(i - 1 + n) % n][j]);
        for (int i = 0; i < n; i++) g[i][j] = tmp[i];
      }
  } else {
    for (int i = 0; i < n; i++)
      if (i & 1) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) tmp.push_back(g[i][(j - 1 + m) % m]);
        tmp.swap(g[i]);
      }
    for (int j = 0; j < m; j++)
      if (j & 1) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) tmp.push_back(g[(i + 2) % n][j]);
        for (int i = 0; i < n; i++) g[i][j] = tmp[i];
      }
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", g[i][j]);
    puts("");
  }
  return 0;
}

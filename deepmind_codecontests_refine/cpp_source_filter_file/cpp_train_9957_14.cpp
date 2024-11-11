#include <bits/stdc++.h>
using namespace std;
int n, m, a[300010], f[300010], p;
vector<int> x[300010], w;
int main() {
  srand(time(0));
  int i, j, k, l;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    a[i] = i + 1;
    for (j = i + i; j <= n; j += i) x[j].push_back(i);
  }
  p = n - 1;
  for (i = 1; i <= p; i++) {
    for (j = 2; j * j <= a[i]; j++)
      if (a[i] % j == 0) break;
    if (j * j > a[i] && a[i] * 2 > n) {
      swap(a[i], a[p]);
      p--;
      i--;
    }
  }
  for (int t = 1; t <= 12; t++) {
    for (i = 1; i <= n; i++) f[i] = 0;
    for (i = 1; i <= p; i++) swap(a[i], a[((rand() << 15) + rand()) % i + 1]);
    for (i = 1, k = 0; i <= p && k < m; i++) {
      for (j = a[i], l = 0; j <= n; j += a[i])
        if (f[j]) l++;
      for (auto j : x[a[i]])
        if (f[j]) l++;
      if (k + l <= m) {
        k += l;
        f[a[i]] = 1;
        w.push_back(a[i]);
      }
      if (k + w.size() >= m - (n - 1 - p)) {
        k += w.size();
        w.push_back(1);
        for (j = p + 1; k < m; j++, k++) w.push_back(a[j]);
        break;
      }
    }
    if (k + w.size() >= m - (n - 1 - p)) {
      k += w.size();
      w.push_back(1);
      for (j = p + 1; k < m; j++, k++) w.push_back(a[j]);
    }
    if (k == m) {
      printf("Yes\n%d\n", w.size());
      for (auto i : w) printf("%d ", i);
      return 0;
    }
    w.clear();
  }
  printf("No\n");
  return 0;
}

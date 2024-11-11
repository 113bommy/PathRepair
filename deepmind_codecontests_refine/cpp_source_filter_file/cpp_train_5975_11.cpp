#include <bits/stdc++.h>
using namespace std;
int a[100007], b[100007], s[100007], id[100007];
bool cmp(int x, int y) { return s[x] < s[y]; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d", s + i), id[i] = i;
  int m = (n + 2) / 3;
  sort(id, id + n);
  for (int i = 0; i < m; ++i) a[id[i]] = i, b[id[i]] = s[id[i]] - a[id[i]];
  for (int i = 0; i < 2 * m && i < n; ++i)
    b[id[i]] = i, a[id[i]] = s[id[i]] - b[id[i]];
  for (int i = n - 1, j = 0; i >= 2 * m; --i, ++j)
    b[id[i]] = j, a[id[i]] = s[id[i]] - b[id[i]];
  puts("YES");
  for (int i = 0; i < n; ++i) {
    printf("%d", a[i]);
    if (i == n - 1)
      puts("");
    else
      printf(" ");
  }
  for (int i = 0; i < n; ++i) {
    printf("%d", b[i]);
    if (i == n - 1)
      puts("");
    else
      printf(" ");
  }
  return 0;
}

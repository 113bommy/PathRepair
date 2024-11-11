#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b;
bool se[100010];
inline int getint() {
  int w = 0, q = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? -w : w;
}
void work1() {
  for (int i = 1; i <= n && m; i++)
    if (i != a && i != b) printf("%d %d\n", a, i), m--;
  for (int i = 1; i <= n && m; i++)
    if (!se[i]) printf("%d %d\n", i, b), m--;
}
void work2() {
  for (int i = 1; i <= n && m; i++)
    if (i != a && i != b)
      for (int j = i + 1; j <= n && m; j++)
        if (j != a && j != b) printf("%d %d\n", a, b);
}
int main() {
  cin >> n >> m >> k;
  if (k >= n || m < n - 1 || m > (n - 1) * (n - 2) / 2 + n - k) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= k; i++) se[getint()] = 1;
  a = 1, b = 1;
  while (!se[a]) a++;
  b = a + 1;
  while (!se[b]) b++;
  work1();
  work2();
  return 0;
}

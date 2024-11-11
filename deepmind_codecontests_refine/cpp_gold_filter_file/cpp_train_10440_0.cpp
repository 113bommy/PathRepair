#include <bits/stdc++.h>
using namespace std;
void file_open() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n > m) swap(n, m);
  if (n == 1)
    printf("%d", m);
  else if (n == 2)
    printf("%d", 2 * (m / 4 * 2 + (m % 4 > 0) + (m % 4 > 1)));
  else
    printf("%d", (n * m + 1) / 2);
  return 0;
}

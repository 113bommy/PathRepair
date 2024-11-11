#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
static void amin(T &x, U y) {
  if (x > y) x = y;
}
int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  vector<int> a(m + 2);
  for (int i = 0; i < (n); i++) {
    scanf("%d", &x);
    for (int j = 0; j < (x); j++) scanf("%d", &y), ++a[y];
  }
  for (int i = 1; i <= m; i++)
    if (!a[i]) return printf("NO\n"), 0;
  printf("YES\n");
  return 0;
}

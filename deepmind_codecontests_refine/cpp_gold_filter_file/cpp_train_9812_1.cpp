#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n = 8;
int first[10], second[10], a[10], b[10];
bool hash[10];
inline int dp(int i, int j, int k) {
  return (first[i] - first[j]) * (first[k] - first[j]) +
         (second[i] - second[j]) * (second[k] - second[j]);
}
inline bool rectangle(int i, int j, int k, int l) {
  return !dp(i, j, k) && !dp(j, k, l) && !dp(k, l, i) && !dp(l, i, j);
}
inline bool square(int i, int j, int k, int l) {
  return rectangle(i, j, k, l) &&
         (((first[i] - first[j]) * (first[i] - first[j])) +
          ((second[i] - second[j]) * (second[i] - second[j]))) ==
             (((first[j] - first[k]) * (first[j] - first[k])) +
              ((second[j] - second[k]) * (second[j] - second[k])));
}
bool dfs(int i, int j, int k) {
  if (i <= n) {
    if (j <= n / 2) {
      a[j] = i;
      if (dfs(i + 1, j + 1, k)) return 1;
    }
    if (k <= n / 2) {
      b[k] = i;
      if (dfs(i + 1, j, k + 1)) return 1;
    }
    return 0;
  } else {
    return (rectangle(a[1], a[2], a[3], a[4]) ||
            rectangle(a[1], a[2], a[4], a[3]) ||
            rectangle(a[1], a[3], a[2], a[4])) &&
           (square(b[1], b[2], b[3], b[4]) || square(b[1], b[2], b[4], b[3]) ||
            square(b[1], b[3], b[2], b[4]));
  }
}
int main() {
  int i;
  for (i = 1; i <= n; ++i) scanf("%d%d", &first[i], &second[i]);
  if (dfs(1, 1, 1)) {
    printf("YES\n");
    for (i = 1; i <= n / 2; ++i) printf("%d%c", b[i], i < n / 2 ? ' ' : '\n');
    for (i = 1; i <= n / 2; ++i) printf("%d%c", a[i], i < n / 2 ? ' ' : '\n');
  } else
    printf("NO\n");
  return 0;
}

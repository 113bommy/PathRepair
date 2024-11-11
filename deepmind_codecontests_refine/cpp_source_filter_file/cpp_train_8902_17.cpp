#include <bits/stdc++.h>
int main() {
  const int MAX = (int)1e5;
  int n, i;
  scanf("%d", &n);
  char direction[MAX];
  scanf("%s", direction);
  int step[MAX];
  int visited[MAX];
  for (i = 0; i < n; i++) {
    visited[i] = 0;
    scanf("%d", &step[i]);
  }
  int pos = 0;
  visited[pos] = 1;
  while (1) {
    if (direction[pos] == '>') {
      pos = pos + step[pos];
    } else {
      pos = pos - step[pos];
    }
    if (pos <= 0 || pos >= n) {
      puts("FINITE");
      break;
    }
    if (visited[pos] == 1) {
      puts("INFINITE");
      break;
    }
    visited[pos] = 1;
  }
  return 0;
}

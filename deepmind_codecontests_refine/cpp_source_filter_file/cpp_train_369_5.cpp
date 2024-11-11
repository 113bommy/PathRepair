#include <bits/stdc++.h>
using namespace std;
int i, n, m, j, y, pos, fed = 0;
int mice[100001], cheese[100001], taken[100001];
int main() {
  scanf("%d %d %d %d", &n, &m, &y, &y);
  for (i = 0; i < n; i++) scanf("%d", &mice[i]);
  for (i = 0; i < m; i++) scanf("%d", &cheese[i]);
  for (i = 0; i < m; i++) taken[i] = -1;
  for (i = 0; i < n; i++) {
    pos = lower_bound(cheese, cheese + m, mice[i]) - cheese;
    if (pos == 0) {
      if (taken[pos] == -1) {
        taken[pos] = cheese[pos] - mice[i];
        fed++;
      } else {
        taken[pos] = cheese[pos] - mice[i];
      }
      continue;
    }
    if (pos == m) {
      if (taken[pos - 1] == -1 || taken[pos - 1] == mice[i] - cheese[pos - 1]) {
        taken[pos - 1] = mice[i] - cheese[pos - 1];
        fed++;
      } else if (taken[pos - 1] > mice[i] - cheese[pos - 1]) {
        taken[pos - 1] = mice[i] - cheese[pos - 1];
      }
      continue;
    }
    {
      if ((mice[i] - cheese[pos - 1]) < (cheese[pos] - mice[i])) {
        if (taken[pos - 1] == -1 ||
            taken[pos - 1] == mice[i] - cheese[pos - 1]) {
          taken[pos - 1] = mice[i] - cheese[pos - 1];
          fed++;
        } else if (taken[pos - 1] > mice[i] - cheese[pos - 1]) {
          taken[pos - 1] = mice[i] - cheese[pos - 1];
        }
      } else if ((mice[i] - cheese[pos - 1]) == (cheese[pos] - mice[i])) {
        if (taken[pos - 1] == -1 ||
            taken[pos - 1] == mice[i] - cheese[pos - 1]) {
          taken[pos - 1] = mice[i] - cheese[pos - 1];
          fed++;
        } else {
          taken[pos] = cheese[pos] - mice[i];
          fed++;
        }
      } else {
        if (taken[pos] == -1) {
          taken[pos] = cheese[pos] - mice[i];
          fed++;
        } else {
          taken[pos] = cheese[pos] - mice[i];
        }
      }
    }
  }
  printf("%d\n", fed);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, x[1000], y[1000], m, len[1000], num[1000];
bool used[1000];
int dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 0; i < m; ++i) scanf("%d", &len[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) num[j] = -2;
    for (int j = 0; j < m; ++j) used[j] = false;
    int k, l;
    for (l = 0; l < m; ++l) {
      if (dist((i - 1 + n) % n, i) + dist((i + 1) % n, i) == len[l]) {
        used[l] = true;
        num[i] = l;
        break;
      }
    }
    if (l == m) continue;
    for (k = (i + 2) % n; k != i; k = (k + 2) % n) {
      bool flag = false;
      for (l = 0; l < m; ++l)
        if (!used[l]) {
          if (dist((k - 1 + n) % n, k) + dist((k + 1) % n, k) == len[l]) {
            used[l] = true;
            num[k] = l;
            flag = true;
            break;
          }
        }
      if (!flag) break;
    }
    if (k == i) {
      puts("YES");
      for (k = 0; k < n; ++k) printf("%d ", num[k + 1] + 1);
      return 0;
    }
  }
  puts("NO");
  return 0;
}

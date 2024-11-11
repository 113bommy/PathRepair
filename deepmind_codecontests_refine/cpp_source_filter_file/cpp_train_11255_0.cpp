#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const char character[] = "./\\";
int n, a[N], tag[N], type[N][N];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int o = 0, r = 0;
  for (register int i = 1; i <= n; ++i) {
    if (tag[i] || a[i] == i) {
      continue;
    }
    vector<int> cycle;
    for (int j = i; !tag[j]; j = a[j]) {
      cycle.push_back(j), tag[j] = 1;
    }
    cycle.push_back(i);
    if (!o) {
      o = i;
      for (register int j = 1; j + 1 < cycle.size(); ++j) {
        int a = cycle[j], b = cycle[j + 1];
        ++r;
        type[r][a] = type[r][b] = 2 - (a < b);
      }
    } else {
      ++r;
      type[r][o] = type[r][cycle[1]] = 1;
      for (register int j = 1; j + 1 < cycle.size(); ++j) {
        int a = cycle[j], b = cycle[j + 1];
        ++r;
        type[r][a] = type[r][b] = 2 - (a < b);
      }
      type[r][i] = 2;
    }
  }
  printf("%d\n", o ? n - 1 : n);
  for (register int i = 1; i <= n; ++i) {
    for (register int j = 1; j <= n; ++j) {
      printf("%c", character[type[i][j]]);
    }
    puts("");
  }
  return 0;
}

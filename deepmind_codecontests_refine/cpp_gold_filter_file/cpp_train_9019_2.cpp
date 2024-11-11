#include <bits/stdc++.h>
using namespace std;
const int MX = 1 * pow(2, 31);
const int MN = 1 * pow(2, -31);
int main() {
  vector<int> v[6];
  int a, b, n, f, i;
  while (scanf("%d", &n) == 1) {
    f = 0;
    for (i = 0; i < n; ++i) {
      scanf("%d%d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
    }
    for (i = 1; i < 6; ++i) {
      if (v[i].size() >= 3 || v[i].size() <= 1) {
        f = 1;
      }
      v[i].clear();
    }
    if (f == 1)
      printf("WIN\n");
    else
      printf("FAIL\n");
  }
  return 0;
}

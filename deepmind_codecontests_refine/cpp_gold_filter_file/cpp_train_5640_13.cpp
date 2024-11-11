#include <bits/stdc++.h>
using namespace std;
int _;
vector<int> v[110000];
int main() {
  bool poss = true;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i += 1) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  if (n == 2) {
    puts("YES");
    return 0;
  }
  int isLeaf[110000] = {0};
  for (int i = 1; i < n + 1; i += 1) {
    if (v[i].size() == 1) isLeaf[i] = 1;
  }
  for (int i = 1; i < n + 1; i += 1) {
    if (isLeaf[i] == 1)
      continue;
    else {
      if (v[i].size() <= 2) {
        poss = false;
        break;
      }
    }
  }
  poss ? puts("YES") : puts("NO");
  return 0;
}

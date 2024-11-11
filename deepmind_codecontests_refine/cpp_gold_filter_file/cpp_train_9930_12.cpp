#include <bits/stdc++.h>
using namespace std;
int indeg[(int)1e5 + 1000];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    indeg[x]++;
    indeg[y]++;
  }
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] != 2) f = 1;
  }
  if (f == 0) {
    printf("ring topology\n");
    return 0;
  }
  vector<int> indeg_1, indeg_n;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 1) {
      indeg_1.push_back(i);
    } else if (indeg[i] == n - 1) {
      indeg_n.push_back(i);
    }
  }
  if (indeg_1.size() == n - 1 && indeg_n.size() == 1) {
    printf("star topology\n");
    return 0;
  }
  indeg_1.clear();
  vector<int> indeg_2;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 1) {
      indeg_1.push_back(i);
    } else if (indeg[i] == 2) {
      indeg_2.push_back(i);
    }
  }
  if (indeg_1.size() == 2 && indeg_2.size() == n - 2) {
    printf("bus topology\n");
    return 0;
  }
  printf("unknown topology\n");
}

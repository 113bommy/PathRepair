#include <bits/stdc++.h>
using namespace std;
vector<int> v[1234567], u[1234567];
int vis[1234567], seen[1234567], sel[1234567], ck = 0;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for (int i = 1; i <= b; i++) {
    int c, d;
    scanf("%d %d", &c, &d);
    v[c].push_back(d);
    u[d].push_back(c);
  }
  for (int i = a; i >= 1; i--) {
    if (!vis[i]) {
      seen[i] = 1;
      vis[i] = 1;
      for (int j = 0; j < v[i].size(); j++) {
        int y = v[i][j];
        if (!vis[y]) vis[y] = 1;
      }
    }
  }
  for (int i = 1; i <= a; i++) {
    if (seen[i]) {
      for (int j = 0; j < u[i].size(); j++) {
        int y = u[i][j];
        if (seen[y]) {
          seen[i] = 0;
          break;
        }
      }
      if (seen[i]) {
        sel[ck++] = i;
      }
    }
  }
  printf("%d\n", ck);
  for (int i = 0; i < ck; i++) printf("%d ", sel[i]);
  printf("\n");
  return 0;
}

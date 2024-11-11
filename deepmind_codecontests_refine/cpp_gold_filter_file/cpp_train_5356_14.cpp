#include <bits/stdc++.h>
using namespace std;
set<int> a;
int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= m; i++) {
    int v;
    scanf("%d\n", &v);
    v %= n;
    if (a.find(v) != a.end()) {
      printf("%d\n", i);
      return 0;
    }
    a.insert(v);
  }
  printf("-1\n");
  return 0;
}

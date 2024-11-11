#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  set<int> tree;
  scanf("%d %d", &n, &p);
  bool printed = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (tree.find(x % p) != tree.end() && !printed)
      printf("%d\n", i + 1), printed = 1;
    else
      tree.insert(x % p);
  }
  if (!printed) puts("-1");
  return 0;
}

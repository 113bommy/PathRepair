#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  set<int> S;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    S.insert(x);
  }
  vector<int> ans;
  for (int i = 1; i <= 1e5; i++) {
    if (S.count(i)) continue;
    if (i > m) continue;
    m -= i;
    ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}

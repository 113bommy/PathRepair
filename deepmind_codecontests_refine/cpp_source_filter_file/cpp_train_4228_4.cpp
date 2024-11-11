#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1000 + 5], b[1000 + 5], ans[1000 + 5];
  int test[1000 + 5] = {};
  vector<int> d;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i])
      d.push_back(i);
    else {
      ans[i] = a[i];
      test[a[i]] = 1;
    }
  }
  if (d.size() == 1) {
    for (int i = 1; i <= n; i++)
      if (test[i] == 0) {
        ans[b[0]] = i;
        break;
      }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  } else {
    if (!test[a[d[0]]] && !test[b[d[1]]]) {
      ans[d[0]] = a[d[0]];
      ans[d[1]] = b[d[1]];
    } else {
      ans[d[0]] = b[d[0]];
      ans[d[1]] = a[d[1]];
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
  return 0;
}

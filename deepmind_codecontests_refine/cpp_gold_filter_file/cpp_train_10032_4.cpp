#include <bits/stdc++.h>
using namespace std;
int a[100005];
bitset<(1 << 20)> found;
set<int> s[100005];
int main() {
  found.reset();
  int n, i, t;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s[i].insert(a[i]);
    found[a[i]] = 1;
  }
  set<int>::iterator it;
  for (i = 1; i < n; i++) {
    for (it = s[i - 1].begin(); it != s[i - 1].end(); it++) {
      t = *it | a[i];
      s[i].insert(t);
      found[t] = 1;
    }
  }
  printf("%d\n", found.count());
  return 0;
}

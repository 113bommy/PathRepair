#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> v;
  v.clear();
  int n, i, j, s;
  scanf("%d", &n);
  int f[100001];
  memset(f, 0, sizeof(f));
  for (i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    v.insert(f[i]);
  }
  for (i = 1; i <= n; i++) {
    s = 0;
    for (j = i - 1; j > 0; j--) {
      s |= f[j];
      if (0 == (f[i] & ~s)) break;
      v.insert(s | f[i]);
    }
  }
  printf("%d", v.size());
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[300010], la[300010], fi[300010];
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      fi[i] = n;
      la[i] = -1;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      --a[i];
      if (fi[a[i]] == n) fi[a[i]] = i;
      la[a[i]] = i;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (la[i] == -1) continue;
      v.push_back(i);
    }
    int m = v.size(), ans = m - 1, R = n, c = 0;
    for (int i = 0; i < v.size(); i++) {
      int x = v[i];
      if (R > fi[x]) {
        c = 0;
      } else {
        ++c;
      }
      R = la[x];
      ans = min(ans, m - c);
    }
    printf("%d\n", ans);
  }
  return 0;
}

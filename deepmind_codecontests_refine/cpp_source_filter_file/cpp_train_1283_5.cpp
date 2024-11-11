#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff, M = (int)(1e5 + 100);
int a[M], b[M];
int main(void) {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] > 0)
        b[a[i]]++;
      else {
        b[-a[i]]--;
        cnt++;
      }
    }
    int k = count(b, b + n, m - cnt);
    for (int i = 0; i < n; i++) {
      if (b[abs(a[i])] + cnt != m)
        puts(a[i] > 0 ? "Lie" : "Truth");
      else if (k == 1)
        puts(a[i] > 0 ? "Truth" : "Lie");
      else
        puts("Not defined");
    }
  }
}

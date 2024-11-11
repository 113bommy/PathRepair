#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int d[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    int u, v;
    for (int i = 1; i < n; ++i) {
      scanf("%d%d", &u, &v);
      ++d[u], ++d[v];
    }
    if (d[x] <= 1) {
      puts("Ayush");
    } else {
      if ((n - 2) & 1 == 0) {
        puts("Ayush");
      } else {
        puts("Ashish");
      }
    }
    memset(d, 0, sizeof d);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k;
int a[N];
bool vis[1000];
int b[10];
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) scanf("%d", &b[j]);
      a[i] = b[1] * 1 + b[2] * 2 + b[3] * 4 + b[4] * 8;
      vis[a[i]] = 1;
    }
    int flag = 0;
    for (int i = 0; i <= 15; i++) {
      for (int j = 0; j <= 15; j++) {
        if (!(i & j) && vis[i] && vis[j]) {
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
}

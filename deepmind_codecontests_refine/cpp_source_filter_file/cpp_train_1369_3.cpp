#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[100010];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int cnt = 0;
  int maxx = a[1];
  for (int i = 1; i <= n; i++) {
    maxx = a[i];
    int j;
    for (j = i + 1; j < maxx; j++) maxx = max(maxx, a[j]);
    i = j;
    cnt++;
  }
  printf("%d\n", cnt);
}

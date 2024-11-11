#include <bits/stdc++.h>
using namespace std;
const long long maxn = 300000;
long long n, p[maxn], sum, vis[maxn], last;
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &p[i]);
  last = n;
  sum = 0;
  printf("1");
  for (int i = 0; i < n; i++) {
    vis[p[i]] = 1;
    sum++;
    while (vis[last]) sum--, last--;
    printf(" %lld", sum + 1);
  }
  printf("\n");
  return 0;
}

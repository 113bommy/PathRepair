#include <bits/stdc++.h>
using namespace std;
long long num[300010];
struct node {
  long long t;
  int ind;
} xo[300010];
bool cmp(node a, node b) {
  if (a.t == b.t) return a.ind < b.ind;
  return a.t < b.t;
}
int main() {
  int n, k, a, b;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long tmp;
    scanf("%I64d", &tmp);
    xo[i].t = xo[i - 1].t ^ tmp;
    xo[i].ind = i;
    num[i] = xo[i].t;
  }
  sort(xo + 1, xo + n + 1, cmp);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long ji = 0, ou = 0;
    for (int j = i; j <= n; j++) {
      if (xo[i].t != xo[j].t) {
        ans += (ji * (ji - 1) / 2) + (ou * (ou - 1) / 2);
        i = j - 1;
        break;
      }
      if (xo[j].ind % 2)
        ji++;
      else
        ou++;
      if (j == n) {
        ans += (ji * (ji - 1) / 2) + (ou * (ou - 1) / 2);
        i = n;
        break;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}

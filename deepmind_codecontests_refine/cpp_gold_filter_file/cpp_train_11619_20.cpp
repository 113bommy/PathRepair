#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int lo, hi, x;
  int cg, cl;
  while (m--) {
    scanf("%d%d%d", &lo, &hi, &x);
    cg = cl = 0;
    for (int i = lo; i <= hi; i++) {
      if (a[i] > a[x])
        cg++;
      else if (a[i] < a[x])
        cl++;
    }
    if (x - lo == cl && hi - x == cg)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}

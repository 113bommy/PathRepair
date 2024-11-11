#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int t;
int main() {
  scanf("%d%d%d", &n, &k, &t);
  if (t <= k) return printf("%d\n", t) * 0;
  if (k < t && t <= n)
    return printf("%d\n", k) * 0;
  else
    return printf("%d\n", t - n + 1) * 0;
}

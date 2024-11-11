#include <bits/stdc++.h>
using namespace std;
int n, k, t;
int main() {
  scanf("%d%d%d", &n, &k, &t);
  if (k < t && t <= n) printf("%d", k);
  if (t <= k)
    printf("%d", t);
  else
    printf("%d", n + k - t);
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
int arr[maxn], ar[maxn];
int main() {
  int a, b, c, d, e, f, g, h;
  scanf("%d%d", &a, &b);
  scanf("%d%d", &e, &f);
  for (d = 1; d <= a; d++) scanf("%d", &arr[d]);
  for (d = 1; d <= b; d++) scanf("%d", &ar[d]);
  if (arr[e] < ar[1]) {
    printf("YES\n");
  } else
    printf("NO\n");
  return 0;
}

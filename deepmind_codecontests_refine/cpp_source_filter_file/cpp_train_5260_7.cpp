#include <bits/stdc++.h>
using namespace std;
int n, k, i;
char a[100010];
int dist(char a, char b) { return abs(int(a) - int(b)); }
int max_dist(char a) { return max(dist(a, 'a'), dist(a, 'z')); }
int main() {
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) scanf(" %c", &a[i]);
  for (i = 0; i < n; i++) {
    if (k == 0) break;
    if (max_dist(a[i]) <= k) {
      k -= max_dist(a[i]);
      if (max_dist(a[i]) == dist(a[i], 'z'))
        a[i] = 'z';
      else
        a[i] == 'a';
      continue;
    }
    if (max_dist(a[i]) == dist(a[i], 'z'))
      a[i] = char(int(a[i]) + k);
    else
      a[i] = char(int(a[i]) - k);
    k = 0;
  }
  if (k > 0) {
    printf("-1\n");
    return 0;
  }
  for (i = 0; i < n; i++) printf("%c", a[i]);
  printf("\n");
  return 0;
}

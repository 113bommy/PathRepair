#include <bits/stdc++.h>
using namespace std;
const int _max = 1e5 + 10;
int n, s;
int a[_max];
int root;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &s);
    root = 0.5 + sqrt(s);
    for (int i = 2; i <= root; i++) {
      if (s % i == 0) a[i]++;
      while (s % i == 0) s /= i;
    }
    if (s > 1) a[s]++;
  }
  int ans = 0;
  for (int i = 1; i < _max; i++) ans = max(ans, a[i]);
  printf("%d", ans);
  return 0;
}

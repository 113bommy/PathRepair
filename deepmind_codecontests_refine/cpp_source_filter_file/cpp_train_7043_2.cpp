#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, l, ans = 0x3f3f3f3f, a[100009], t;
  scanf("%d %d", &w, &l);
  int k = l;
  int temp = 0;
  a[0] = 0;
  for (int i = 1; i < w; i++) {
    scanf("%d", &t);
    a[i] += (a[i - 1] + t);
  }
  for (int i = l; i < w; i++) {
    ans = min(ans, a[i] - a[i - l]);
  }
  printf("%d\n", ans);
}

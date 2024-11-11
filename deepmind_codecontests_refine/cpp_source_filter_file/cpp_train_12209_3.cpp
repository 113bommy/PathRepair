#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, t;
  scanf("%d %d", &n, &t);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  int op = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] * 2 == t) {
      if (op)
        printf("1 ");
      else
        printf("0 ");
      op ^= 1;
      continue;
    }
    if (v[i] < t / 2)
      printf("1 ");
    else
      printf("0 ");
  }
  printf("\n");
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}

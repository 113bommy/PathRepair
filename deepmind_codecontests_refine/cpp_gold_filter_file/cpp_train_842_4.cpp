#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[2333];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    if (i % 3 == 0)
      a[i] = {(i / 3) * 2 + 1, 0};
    else if (i % 3 == 1)
      a[i] = {(i / 3) * 2, 0};
    else
      a[i] = {(i / 3) * 2 + 1, 3};
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", a[i].first, a[i].second);
}

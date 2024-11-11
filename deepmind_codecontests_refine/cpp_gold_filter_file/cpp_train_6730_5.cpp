#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 200000 + 10;
const int mod = 1000000007;
set<int> s;
int main() {
  int a[101000], Min = inf, Max = -inf, Mid, n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
    Min = min(Min, a[i]);
    Max = max(Max, a[i]);
  }
  if (Max - Min != 2) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%d\n", a[i]);
    printf("\n");
    return 0;
  }
  Mid = Min + 1;
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == Min)
      x++;
    else if (a[i] == Mid)
      y++;
    else
      z++;
  }
  int sum = 0;
  if (y / 2 > min(x, z)) {
    x += y / 2;
    z += y / 2;
    sum = y / 2 * 2;
    y = y % 2;
  } else {
    sum = 2 * min(x, z);
    int tt = min(x, z);
    x -= tt;
    z -= tt;
    y += sum;
  }
  printf("%d\n", n - sum);
  for (int i = 0; i < x; i++) printf("%d ", Min);
  for (int i = 0; i < y; i++) printf("%d ", Mid);
  for (int i = 0; i < z; i++) printf("%d ", Max);
  printf("\n");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int a[N], tmp[N], cnt;
double cc(int x) {
  if (x == 0) return 0.0;
  return 2.0 * x - 1.0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] > a[j]) cnt++;
  printf("%.7f\n", cc(cnt));
  return 0;
}

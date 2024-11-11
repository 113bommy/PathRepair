#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, v;
int a[N];
int main() {
  scanf("%d%d", &n, &v);
  int m = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (a[i] > v) m = a[i];
  }
  if (sum - m > v)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}

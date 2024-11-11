#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100010;
int n, m;
int arr[2200], vis[2200];
int k1, k2, k3;
int main() {
  int i, j, k, flag = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  long long sum = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j < i; j++) {
      if (arr[j] > arr[i]) sum++;
    }
  }
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int k = r - l;
    int s1 = 0;
    s1 = (1 + r - l) * (r - l) / 2;
    sum += s1;
    if (sum % 2 == 1)
      printf("odd\n");
    else
      printf("even\n");
  }
  return 0;
}

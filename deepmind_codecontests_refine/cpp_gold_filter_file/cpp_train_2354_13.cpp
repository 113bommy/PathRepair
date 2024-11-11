#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long inf = 0x4f4f4f4f4f;
int n, k;
int a[maxn];
int main() {
  scanf("%d", &n);
  int tmp = 0, tmp1 = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 != 0) tmp++;
  }
  if (tmp > 0) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
}

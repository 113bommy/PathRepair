#include <bits/stdc++.h>
using namespace std;
int cnt[100010];
int main() {
  int n, k, a;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    cnt[i % k] += a;
  }
  int MIN = 1000000000, index = 0;
  for (int i = 0; i < k; i++) {
    if (cnt[i] < MIN) {
      MIN = cnt[i];
      index = i;
    }
  }
  printf("%d\n", index + 1);
  return 0;
}

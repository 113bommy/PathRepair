#include <bits/stdc++.h>
using namespace std;
int cnt[10005];
int n;
int main() {
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    cnt[a]++;
    cnt[b]++;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += cnt[i] * (cnt[i] - 1) / 2;
  }
  printf("%d\n", sum);
  return 0;
}

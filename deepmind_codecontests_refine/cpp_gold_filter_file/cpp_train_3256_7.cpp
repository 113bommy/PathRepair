#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int p[N], st[N], tot;
void init(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) p[++tot] = i;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      st[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int cnt[N];
int main() {
  init(1000001);
  cnt[0] = 1;
  for (int i = 1; i <= tot; i++) cnt[p[i]]++;
  for (int i = 1; 1LL * p[i] * p[i] <= 1000000; i++) cnt[p[i] * p[i]]--;
  for (int i = 1; i <= 1000000; i++) cnt[i] += cnt[i - 1];
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", cnt[n]);
  }
  return 0;
}

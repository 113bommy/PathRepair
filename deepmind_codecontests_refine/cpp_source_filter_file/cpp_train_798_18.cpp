#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 77;
int n, k, d, a[N], fen[N];
bool dp[N];
void update(int x) {
  for (; x < N; x += x & (-x)) {
    fen[x]++;
  }
}
int get(int x) {
  int res = 0;
  for (; x; x -= x & (-x)) {
    res += fen[x];
  }
  return res;
}
int get(int l, int r) { return get(r) - get(l - 1); }
int main() {
  scanf("%d %d %d", &n, &k, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  for (int i = k; i <= n; i++) {
    if (a[i] - a[1] <= d) {
      update(i);
      dp[i] = 1;
      continue;
    }
    int r = i - k + 1;
    int l = lower_bound(a + 1, a + 1 + n, a[i] - d) - a - 1;
    if (get(l, r) > 0) {
      update(i);
      dp[i] = 1;
    }
  }
  if (dp[n]) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
int arr[10], n, k;
long long ans1, ans2;
bool walk(int beg) {
  int cur = beg, cnt = 0;
  while (cnt <= k) {
    if (cur == 1) return true;
    cur = arr[cur];
    cnt++;
  }
  return false;
}
bool chk() {
  for (int i = 1; i <= k; i++)
    if (!walk(i)) return false;
  return true;
}
void dfs(int dep) {
  if (dep == k + 1) {
    if (chk()) ans2++;
    if (ans2 >= INF) ans2 -= INF;
    return;
  }
  for (int i = 1; i <= k; i++) {
    arr[dep] = i;
    dfs(dep + 1);
  }
}
long long mod(int a, int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b & 1) {
    return (a * mod(a, b - 1)) % INF;
  } else {
    long long tmp = mod(a, b >> 1) % INF;
    return (tmp * tmp) % INF;
  }
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    ans1 = mod(n - k, n - k);
    ans2 = 0;
    dfs(1);
    long long ans = (ans1 * ans2) % INF;
    printf("%I64d\n", ans);
  }
  return 0;
}

#include <bits/stdc++.h>
int setBit(int N, int pos) { return N = N | (1 << pos); }
int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
using namespace std;
int n, t, arr[10005], freq[305], bound;
int dp[10005][305];
bool visit[10005][305];
void append() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 1; j * n < bound; j++) {
      arr[j * n + i] = arr[i];
    }
  }
}
int DP(int idx, int prev) {
  if (idx >= bound) return 0;
  if (visit[idx][prev]) return dp[idx][prev];
  visit[idx][prev] = true;
  int ret1 = 0, ret2 = 0;
  if (arr[idx] >= prev) ret1 = 1 + DP(idx + 1, arr[idx]);
  ret2 = DP(idx + 1, prev);
  return dp[idx][prev] = max(ret1, ret2);
}
int main() {
  int i;
  scanf("%d %d", &n, &t);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    freq[arr[i]]++;
  }
  bound = min(t, 100) * n;
  append();
  int ans = DP(0, 0);
  if (t <= 100)
    printf("%d\n", ans);
  else {
    int add = *max_element(freq, freq + 302);
    printf("%d\n", ans + (t - 100) * add);
  }
  return 0;
}

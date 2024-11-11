#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int cnt[N], ans[N], temp[N];
int main() {
  int n, x;
  scanf("%d", &n);
  fill(temp, temp + N, INF);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    for (int up = 0, top = x; top >= 1; up++, top /= 2) {
      for (int down = 0, bot = top; bot < N; down++, bot *= 2) {
        temp[bot] = min(temp[bot], up + down);
      }
    }
    for (int up = 0, top = x; top >= 1; up++, top /= 2) {
      for (int down = 0, bot = top; bot < N; down++, bot *= 2) {
        if (temp[bot] == INF) continue;
        cnt[bot]++;
        ans[bot] += temp[bot];
        temp[bot] = INF;
      }
    }
  }
  int _min = INF;
  for (int i = 1; i < 10; i++) {
    if (cnt[i] == n) {
      _min = min(_min, ans[i]);
    }
  }
  printf("%d\n", _min);
  return 0;
}

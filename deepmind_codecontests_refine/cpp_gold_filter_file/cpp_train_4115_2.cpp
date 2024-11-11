#include <bits/stdc++.h>
#pragma comment(linker, "/stack:102400000,102400000")
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 5e5 + 10;
const int MOD = 1e9 + 7;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int seed = 131;
int cases = 0;
int arr[MAXN << 1];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1, cnt = 1; i <= n / 2; ++i, cnt += 2)
    arr[i] = arr[i + n - cnt] = cnt;
  for (int i = n + 1, cnt = 2; i <= n + n / 2; ++i, cnt += 2)
    arr[i] = arr[i + n - cnt] = cnt;
  for (int i = 1; i <= (n << 1); ++i) printf("%d ", arr[i] ? arr[i] : n);
  return 0;
}

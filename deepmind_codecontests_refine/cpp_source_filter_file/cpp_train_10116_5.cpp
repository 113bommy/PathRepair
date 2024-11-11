#include <bits/stdc++.h>
const int MAXN = 1e5 + 1;
int N;
long long a[MAXN];
int f[63][MAXN], id[MAXN], K;
int sum[2][MAXN];
bool cmp(int x, int y) { return (a[x] & K) < (a[y] & K); }
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> a[i];
  }
  std::sort(a + 1, a + N + 1);
  for (int i = 1; i <= N; i++) {
    a[i] = a[N] - a[i];
    id[i] = i;
  }
  memset(f, 63, sizeof(f));
  f[0][0] = 0;
  for (int k = 0; k < 62; ++k) {
    K = 1ll << k;
    --K;
    std::sort(id + 1, id + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
      sum[0][i] = sum[0][i - 1];
      sum[1][i] = sum[1][i - 1];
      sum[a[id[i]] >> k & 1][i]++;
    }
    for (int i = 0; i <= N; i++) {
      int w, rever;
      w = sum[1][N - i] + sum[0][N] - sum[0][N - i];
      rever = sum[1][N] - sum[1][N - i];
      f[k + 1][rever] = std::min(f[k + 1][rever], f[k][i] + w);
      w = sum[0][N - i] + sum[1][N] - sum[1][N - i];
      rever = N - sum[0][N - i];
      f[k + 1][rever] = std::min(f[k + 1][rever], f[k][i] + w);
    }
  }
  std::cout << f[62][0] << '\n';
  return 0;
}

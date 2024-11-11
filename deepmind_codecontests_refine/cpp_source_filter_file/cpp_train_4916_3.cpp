#include <bits/stdc++.h>
int count[5001];
int N, mid;
int pr[670], v, m[5001];
int num_div[5001], num_div_frac[5001];
int count_div[670][5001], used_div[670], next_div_count[670], use_cur[5001];
long long O;
inline int abs(int x) { return x < 0 ? -x : x; }
int main() {
  for (int i = 2; i <= 5000; i++) {
    if (!m[i]) m[i] = pr[++v] = i;
    for (int j = 1; j <= v && pr[j] * i <= 5000 && pr[j] <= m[i]; j++)
      m[pr[j] * i] = pr[j];
  }
  for (int i = 2; i <= 5000; i++) num_div[i] = num_div[i / m[i]] + 1;
  for (int i = 1; i <= 5000; i++)
    num_div_frac[i] = num_div_frac[i - 1] + num_div[i];
  for (int i = 1; i <= v; i++)
    for (int j = 1; j <= 5000; j++)
      count_div[i][j] = j / pr[i] + count_div[i][j / pr[i]];
  scanf("%d", &N);
  for (int i = 1, x; i <= N; i++) {
    scanf("%d", &x);
    count[x]++;
    O += num_div_frac[x];
  }
  for (int i = 1; i <= 5000; i++) use_cur[i] = v;
  int L = 1, R = 5000;
  while (1) {
    for (int i = 0; i <= v; i++) next_div_count[i] = 0;
    for (int i = L; i <= R; i++) {
      while (use_cur[i] && used_div[use_cur[i]] == count_div[use_cur[i]][i])
        use_cur[i]--;
      next_div_count[use_cur[i]] += count[i];
    }
    int next = 0;
    for (int i = 1; i <= v; i++)
      if (next_div_count[i] << 1 > N) next = i;
    if (next == 0) break;
    O = O + N - 2 * next_div_count[next];
    used_div[next]++;
    int tL = std::lower_bound(use_cur + L, use_cur + R + 1, next) - use_cur;
    int tR = std::lower_bound(use_cur + L, use_cur + R + 1, next) - use_cur - 1;
    L = tL;
    R = tR;
  }
  printf("%lld\n", O);
  return 0;
}

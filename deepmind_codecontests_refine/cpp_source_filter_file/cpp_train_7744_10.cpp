#include <bits/stdc++.h>
using std::min;
const int MAXN = 4005;
int n, k;
int w[MAXN][MAXN], sum[MAXN][MAXN];
int use[MAXN], dp[MAXN];
template <const int CACHE, const int MB = 1 << 20, const int SIZE = CACHE *MB>
class IO {
 private:
  char *is, *it;
  char ibuf[SIZE];
  char get() {
    if (is == it) {
      is = ibuf;
      it = is + fread(ibuf, 1, SIZE, stdin);
      if (is == it) return EOF;
    }
    return *(is++);
  }

 public:
  IO() { is = it = ibuf; }
  template <typename type>
  IO &operator>>(type &x) {
    char c;
    do {
      c = get();
    } while (!isdigit(c));
    x = c ^ '0';
    while (c = get(), isdigit(c)) x = x * 10 + (c ^ '0');
    return *this;
  }
};
inline int bin_chop(int x, int y) {
  int l = x + 1, r = n;
  while (l <= r) {
    int mid = l + r >> 1;
    if (dp[x] + sum[x + 1][mid] > dp[y] + sum[y + 1][mid])
      l = mid + 1;
    else
      r = mid - 1;
  }
  return r;
}
inline int DP(int cost) {
  static int dq[MAXN];
  int head = 1, tail = 1;
  dq[1] = dp[0] = use[0] = 0;
  for (int i = 1; i <= n; ++i) {
    while (head < tail && dp[dq[head]] + sum[dq[head] + 1][i] >=
                              dp[dq[head + 1]] + sum[dq[head + 1] + 1][i])
      ++head;
    dp[i] = dp[dq[head]] + sum[dq[head] + 1][i] + cost;
    use[i] = use[dq[head]] + 1;
    while (head < tail &&
           bin_chop(dq[tail], dq[tail - 1]) >= bin_chop(i, dq[tail - 1]))
      --tail;
    dq[++tail] = i;
  }
  return dp[n];
}
inline int bin_chop() {
  int l = 0, r = 160000000;
  while (l <= r) {
    int mid = l + r >> 1;
    DP(mid);
    if (use[n] >= k)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return DP(r) - r * k;
}
inline void pre_cal() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) w[i][j] += w[i][j - 1];
    memset(w[i] + i, 0, n - i + 1 << 2);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j)
      sum[i][j] = sum[i][j - 1] + w[j][j - 1] - w[j][i - 1];
  }
}
int main() {
  static IO<8> io;
  io >> n >> k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) io >> w[i][j];
  }
  pre_cal();
  printf("%d", bin_chop());
  return 0;
}

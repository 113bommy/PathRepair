#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
template <typename T>
inline void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = (ch == '-') ? -1 : 1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T& x, Args&... args) {
  read(x), read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T, typename... Args>
inline void write(T& x, Args&... args) {
  write(x), putchar('\n'), write(args...);
}
constexpr int MAXN = 2e5 + 5, MOD = 1e9 + 7;
int n, m, x[MAXN], y[MAXN], B, pref, a[MAXN], in[MAXN];
int cnt[256][256];
void block_update(int s, int k, int tag) {
  int b = x[k] + y[k];
  for (int i = max(0, s % b - y[k]); i < s % b; i++) cnt[b][i] += tag;
  for (int i = s % b + x[k]; i < b; i++) cnt[b][i] += tag;
}
int block_query(int t) {
  int res = 0;
  for (int i = 2; i <= B; i++) res += cnt[i][t % i];
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> m;
  B = min(255LL, llround(sqrt(m)) + 1);
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int t = 1; t <= m; t++) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      if (x[k] + y[k] >= B) {
        for (int cur = t + x[k]; cur <= m; cur += x[k] + y[k]) {
          a[cur]++;
          if (cur + y[k] <= m) a[cur + y[k]]--;
        }
      } else
        block_update(t, k, 1);
      in[k] = t;
    } else {
      if (x[k] + y[k] >= B) {
        for (int cur = in[k] + x[k]; cur <= m; cur += x[k] + y[k]) {
          a[cur]--;
          if (cur + y[k] <= m) a[cur + y[k]]++;
          if (cur + 1 <= t && t <= cur + y[k]) pref--;
        }
      } else
        block_update(in[k], k, -1);
    }
    pref += a[t];
    cout << pref + block_query(t) << "\n";
  }
  return 0;
}

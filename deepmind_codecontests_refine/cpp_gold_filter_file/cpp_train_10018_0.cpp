#include <bits/stdc++.h>
using namespace std;
void re(int& x);
template <class T, class... Ts>
void re(T& t, Ts&... ts);
void pr(long long x);
void pr(const char* x);
void ps();
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts);
long long pd[2100][2100];
long long pd2[2100][2100];
int agggg[2100];
int cost[2100];
int value[4100];
int first[2100][2100];
int seen[2100][2100];
int n, m;
long long rec2(int pos, int min_agg);
long long rec(int pos, int hm) {
  if (pos == -1) return 0;
  int ohm = hm;
  long long& ret = pd[pos][hm];
  if (!seen[pos][hm]) {
    seen[pos][hm] = 1;
    ret = -1000000000000000000LL;
    int cur_agg = agggg[pos];
    long long cur_cost = 0;
    while (1) {
      if (hm == 0) {
        ret = max(ret, cur_cost + rec2(pos - 1, cur_agg));
        break;
      }
      int next_pos = (pos == 0 ? -1 : first[cur_agg][pos - 1]);
      if (next_pos != -1) ret = max(ret, cur_cost + rec(next_pos, hm));
      if (next_pos != -1)
        ret = max(ret, cur_cost + value[cur_agg] - cost[next_pos] +
                           rec(next_pos, hm + 1));
      hm /= 2;
      cur_agg++;
      cur_cost += hm * 1ll * value[cur_agg];
    }
  }
  return ret;
}
long long rec2(int pos, int min_agg) {
  if (pos == -1 || min_agg > m) return 0;
  long long& ret = pd2[pos][min_agg];
  if (ret == -1) {
    ret = rec2(pos - 1, min_agg);
    if (agggg[pos] >= min_agg)
      ret = max(ret, value[agggg[pos]] - cost[pos] + rec(pos, 1));
  }
  return ret;
}
void solve() {
  memset(pd2, -1, sizeof(pd2));
  re(n, m);
  for (int i = 0; i < n; i++) {
    re(agggg[i]);
  }
  agggg[n] = 0;
  for (int i = 0; i < n; i++) re(cost[i]);
  for (int i = 1; i <= n + m; i++) re(value[i]);
  for (int a = m + 50; a >= 0; a--) {
    first[a][0] = (agggg[0] == a) ? 0 : -1;
    for (int i = 1; i <= n; i++)
      first[a][i] = (agggg[i] == a ? i : first[a][i - 1]);
  }
  long long ans = rec2(n - 1, 0);
  ps(ans);
}
int main() { solve(); }
void re(int& x) { scanf("%d", &x); }
template <class T, class... Ts>
void re(T& t, Ts&... ts) {
  re(t);
  re(ts...);
}
void pr(long long x) { printf("%lld", x); }
void pr(const char* x) { printf("%s", x); }
void ps() { pr("\n"); }
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(" ");
  ps(ts...);
}

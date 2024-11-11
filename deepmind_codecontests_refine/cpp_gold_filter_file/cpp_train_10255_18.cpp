#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double eps = 1e-8;
const int maxn = 1e4 + 4;
const int mod = 1e9 + 7;
const int inf = 0x7f7f7f7f;
inline int scan() {
  long long m = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') m = m * 10 + c - '0', c = getchar();
  return int(m * f);
}
int N, T;
int p[maxn], s[maxn], cnt, loc[maxn], d[maxn];
int l[maxn], r[maxn];
pair<int, int> ans[2000200];
int find(int x) {
  if (r[x] == x) return x;
  return r[x] = find(r[x]);
}
int main() {
  cin >> N;
  r[N + 1] = N + 1;
  for (int i = 1; i <= N; i++) {
    scanf("%d", p + i);
    r[i] = i;
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", s + i);
    loc[s[i]] = i;
    if (s[i] == p[i]) r[i] = i + 1;
  }
  for (int i = 1; i <= N; i++) {
    d[i] = loc[p[i]] - i;
  }
  int sum = 0;
  while (1) {
    bool flag = 0;
    for (int i = 1; i < N; i++) {
      if (d[i] > 0) {
        int rr = find(find(i) + 1);
        if (rr > N) continue;
        if (d[rr] <= i - rr) {
          sum += rr - i;
          ans[cnt++] = make_pair(i, rr);
          swap(p[i], p[rr]);
          d[i] += i - rr;
          d[rr] -= i - rr;
          swap(d[i], d[rr]);
          flag = 1;
          if (p[i] == s[i]) r[i] = i + 1;
          if (p[rr] == s[rr]) r[rr] = rr + 1;
        }
      }
    }
    if (!flag) break;
  }
  printf("%d %d \n", sum, cnt);
  for (int i = 0; i < cnt; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long Inf = 1e18;
const int N = 510;
const int mod = 0;
long long gi() {
  long long x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
template <typename T>
bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
};
template <typename T>
bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
};
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
void inc(int &a, int b) { a = (a + b >= mod ? a + b - mod : a + b); }
void dec(int &a, int b) { a = (a - b < 0 ? a - b + mod : a - b); }
int n, m, v[N], st[N], cnt[4], c[N], tp = 0;
long long w[N], ans[3];
vector<pair<int, int> > tr[100010];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) w[i] = gi();
  for (int s = 2; s <= 2 * m; s++) {
    for (int i = 1; i <= n; i++) v[i] = w[i] % s;
    tp = 0;
    for (int i = 1; i <= n; i++) {
      int l = max(s - m, v[i] + 1), r = (s - 1) / 2;
      if (l <= r) st[++tp] = l, tr[l].push_back(make_pair(i, 0));
      l = max(1, s - m), r = min(v[i], min(s - v[i] - 1, (s - 1) / 2));
      if (l <= r) st[++tp] = l, tr[l].push_back(make_pair(i, 1));
      l = max(s - m, max((v[i] + 2) / 2, s - v[i])), r = (s - 1) / 2;
      if (l <= r) st[++tp] = l, tr[l].push_back(make_pair(i, 2));
      l = max(1, max(s - m, s - v[i])), r = min(v[i] / 2, (s - 1) / 2);
      if (l <= r) st[++tp] = l, tr[l].push_back(make_pair(i, 3));
    }
    sort(st + 1, st + tp + 1);
    tp = unique(st + 1, st + tp + 1) - st - 1;
    st[++tp] = (s - 1) / 2 + 1;
    for (int i = 1; i <= n; i++) c[i] = -1;
    for (int i = 0; i < 4; i++) cnt[i] = 0;
    for (int i = 1; i < tp; i++) {
      int l = st[i], r = st[i + 1] - 1;
      for (pair<int, int> x : tr[l]) {
        if (c[x.first] != -1) cnt[c[x.first]]--;
        cnt[c[x.first] = x.second]++;
      }
      if (cnt[1])
        ans[2] += r - l + 1;
      else if (cnt[3] >= 2)
        ans[2] += r - l + 1;
      else if (cnt[3] == 1) {
        if (cnt[2] & 1)
          ans[2] += r - l + 1;
        else
          ans[1] += r - l + 1;
      } else
        ans[cnt[2] & 1] += r - l + 1;
      tr[st[i]].clear();
    }
  }
  ans[0] *= 2;
  ans[1] *= 2;
  for (int s = 1; s <= m; s++) {
    long long cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (w[i] % (s + s)) / s;
    ans[cnt & 1]++;
  }
  printf("%lld %lld %lld %lld\n", ans[2], ans[2], ans[1], ans[0]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
const int N = 1e5 + 5, M = 8, L = 2 * M, S = 1 << 11;
int n;
char s[N];
int g2[M][M], state[N], g[M][N];
vector<int> lk[M];
int sum[S];
long long cnt[L + 3];
namespace OR {
int a[1 << M], b[1 << M];
long long c[1 << M];
void get_s(int a[]) {
  for (int i = 0; i <= M - 1; ++i)
    for (int s = 0; s <= (1 << M) - 1; ++s)
      if (s & (1 << i)) a[s] += a[s - (1 << i)];
}
void get_niv(long long a[]) {
  for (int i = 0; i <= M - 1; ++i)
    for (int s = 0; s <= (1 << M) - 1; ++s)
      if (s & (1 << i)) a[s] -= a[s - (1 << i)];
}
void work() {
  get_s(a);
  get_s(b);
  for (int i = 0; i <= (1 << M) - 1; ++i) c[i] = (long long)a[i] * b[i];
  get_niv(c);
}
};  // namespace OR
void work(int c1, int c2) {
  int *a1 = sum + (c1 << M), *a2 = sum + (c2 << M);
  int s1 = 0, s2 = 0;
  for (int i = 0; i <= (1 << M) - 1; ++i) {
    s1 += a1[i];
    s2 += a2[i];
  }
  if (!s1 || !s2) return;
  static int h[L * 2 + 2];
  memset(h, 0, sizeof(h));
  for (int c = 0; c <= M - 1; ++c) h[g2[c1][c] + g2[c2][c]] |= 1 << c;
  int mn = 0;
  while (!h[mn]) ++mn;
  int t0 = h[mn], t1 = h[mn + 1];
  memcpy(OR::a, a1, sizeof(OR::a));
  memcpy(OR::b, a2, sizeof(OR::b));
  OR::work();
  long long ans1 = (long long)s1 * s2;
  for (int i = 0; i <= (1 << M) - 1; ++i)
    if ((i & t0) == t0) ans1 -= OR::c[i];
  cnt[mn + 1] += ans1;
  memcpy(OR::a, a1, sizeof(OR::a));
  memcpy(OR::b, a2, sizeof(OR::b));
  for (int i = 0; i <= (1 << M) - 1; ++i)
    if ((i & t0) != t0) OR::a[i] = OR::b[i] = 0;
  OR::work();
  long long ans2 = 0;
  for (int i = 0; i <= (1 << M) - 1; ++i)
    if ((i & t1) == t1) ans2 += OR::c[i];
  cnt[mn + 3] += ans2;
  cnt[mn + 2] += (long long)s1 * s2 - (ans1 + ans2);
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) lk[s[i] -= 'a'].push_back(i);
  for (int i = 1; i <= n; ++i) state[i] = s[i] << 8;
  for (int c = 0; c <= M - 1; ++c) {
    deque<pair<int, int> > q;
    int *g2 = ::g2[c], *g = ::g[c];
    for (int c2 = 0; c2 <= M - 1; ++c2) g2[c2] = L;
    for (int i = 1; i <= n; ++i) g[i] = L;
    auto push = [&](int x, int d) {
      if (g[x] > d) {
        g[x] = d;
        q.push_back({1, x});
        if (g2[s[x]] > d) {
          g2[s[x]] = d;
          q.push_back({2, s[x]});
        }
      }
    };
    for (auto i : lk[c]) push(i, 0);
    while (!q.empty())
      if (q.front().first == 1) {
        int x = q.front().second;
        q.pop_front();
        if (x > 1) push(x - 1, g[x] + 1);
        if (x < n) push(x + 1, g[x] + 1);
      } else {
        int c2 = q.front().second;
        q.pop_front();
        for (auto x : lk[c2]) push(x, g2[c2] + 1);
      }
    for (int i = 1; i <= n; ++i) state[i] |= g[i] - g2[s[i]] << c;
  }
  for (int i = 1; i <= n; ++i) ++sum[state[i]];
  for (int c1 = 0; c1 <= M - 1; ++c1) work(c1, c1);
  for (int s1 = 0; s1 <= S - 1; ++s1)
    if (sum[s1]) {
      int c1 = s1 >> M;
      int mn = L;
      for (int c = 0; c <= M - 1; ++c)
        chmin(mn,
              g2[c1][c] + ((s1 >> c) & 1) + g2[c1][c] + ((s1 >> c) & 1) + 1);
      cnt[mn] -= sum[s1];
    }
  for (int i = 1; i <= L; ++i) cnt[i] /= 2;
  for (int c1 = 0; c1 <= M - 1; ++c1)
    for (int c2 = c1 + 1; c2 <= M - 1; ++c2) work(c1, c2);
  for (int i = n; i >= 1; --i) {
    int s1 = state[i], c1 = s[i];
    for (int j = min(n, i + L - 1); j >= i + 1; --j) {
      int s2 = state[j], c2 = s[j];
      int mn = L;
      for (int c = 0; c <= M - 1; ++c)
        chmin(mn,
              g2[c1][c] + ((s1 >> c) & 1) + g2[c2][c] + ((s2 >> c) & 1) + 1);
      if (j - i < mn) {
        ++cnt[j - i];
        --cnt[mn];
      }
    }
  }
  int mx = L;
  while (!cnt[mx]) --mx;
  cout << mx << " " << cnt[mx] << endl;
}

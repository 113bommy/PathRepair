#include <bits/stdc++.h>
using namespace std;
inline unsigned long long Rand() {
  return ((unsigned long long)rand() * rand() * rand() * 236484161 +
          (unsigned long long)rand() * 236484161);
}
const int N = 2e5 + 5;
vector<int> v[N];
map<unsigned long long, long long> mp1, mp2;
unsigned long long val[N], sum[N];
int vis[N];
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  x = f ? -x : x;
}
int main() {
  int n, m;
  read(n), read(m);
  for (int i = 1, l, r; i <= n; ++i) {
    read(l), read(r);
    val[i] = Rand();
    ++vis[l], --vis[r + 1];
    sum[l] ^= val[i], sum[r + 1] ^= val[i];
    v[l].push_back(i);
  }
  for (int i = 1; i <= m; ++i) vis[i] += vis[i - 1], sum[i] ^= sum[i - 1];
  for (int i = 1; i <= m; ++i) sum[i] ^= sum[i - 1];
  long long ans = 0;
  unsigned long long tag = 0;
  for (int i = 1; i <= m; ++i) {
    tag ^= sum[i] ^ sum[i - 1];
    for (int j = 0; j < v[i].size(); ++j) tag ^= val[v[i][j]];
    ++mp1[tag], mp2[tag] += (i - 1);
    ans += (long long)i * mp1[tag] - mp2[tag];
  }
  for (int i = 1, r, len; i <= m; ++i) {
    if (vis[i]) continue;
    r = i;
    while (r < m && !vis[r + 1]) ++r;
    len = r - i + 1;
    for (int j = 1; j <= len; ++j) ans -= (long long)j * (len - j + 1);
    i = r;
  }
  printf("%I64d\n", ans);
  return 0;
}

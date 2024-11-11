#include <bits/stdc++.h>
using namespace std;
const int N = 100005, S = 100;
int L[N], R[N], bel[N], to[N];
long long a[N], b[N], taga[N], tagb[N];
long double slope(int x, int y) {
  if (a[x] == a[y]) {
    if (b[x] == b[y]) return 1;
    return b[x] < b[y] ? 1e18 : -1e18;
  }
  return (long double)(b[y] - b[x]) / (a[y] - a[x]);
}
vector<int> s[N / S + 5];
int pos[N / S + 5];
void build(int x) {
  for (int i = L[x]; i <= R[x]; i++) b[to[i]] += a[to[i]] * taga[x] + tagb[x];
  taga[x] = tagb[x] = 0;
  s[x].clear();
  int top = 0;
  for (int i = L[x]; i <= R[x]; i++) {
    while (top > 1 &&
           slope(s[x][top - 2], s[x][top - 1]) <= slope(s[x][top - 1], to[i]))
      --top, s[x].pop_back();
    ++top, s[x].push_back(to[i]);
  }
  pos[x] = 0;
}
inline long long calc(int x) {
  return a[x] * taga[bel[x]] + b[x] + tagb[bel[x]];
}
long long querymax(int x) {
  while (pos[x] < s[x].size() - 1) {
    if (calc(s[x][pos[x]]) > calc(s[x][pos[x] + 1])) break;
    pos[x]++;
  }
  return calc(s[x][pos[x]]);
}
bool cmp(const int& x, const int& y) { return a[x] < a[y]; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), b[i] = a[i], to[i] = i;
  for (int i = 1; i <= n; i++) bel[i] = (i - 1) / S + 1;
  for (int i = 1; i <= bel[n]; i++)
    L[i] = S * (i - 1) + 1, R[i] = min(S * i, n),
    sort(to + L[i], to + R[i] + 1, cmp);
  for (int i = 1; i <= bel[n]; i++) build(i);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long mx = -1ll << 60ll;
    int p;
    for (int j = 1; j <= bel[n]; j++)
      if (querymax(j) > mx) mx = querymax(j), p = s[j][pos[j]];
    if (mx > 0 && p != 0)
      ans += mx;
    else
      break;
    b[p] = -1ll << 60ll;
    for (int j = 1; j < bel[p]; j++) tagb[j] += a[p];
    for (int j = bel[p] + 1; j <= bel[n]; j++) taga[j]++;
    for (int j = L[bel[p]]; j < p; j++) b[j] += a[p];
    for (int j = p + 1; j <= R[bel[p]]; j++) b[j] += a[j];
    build(bel[p]);
  }
  printf("%lld", ans);
  return 0;
}

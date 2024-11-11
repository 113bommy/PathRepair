#include <bits/stdc++.h>
using namespace std;
const int N = 5145;
vector<int> v[N];
int m, n, s, k, j, ct, tt, w[N], as[N], d[N], f[N], c[N], nt[N], ls[N];
pair<int, int> a[N], to[N];
int W(int a, int b) { return min(abs(a - b), m - abs(a - b)); }
void sol(int x, int nw) {
  f[x] = 1e9;
  int oo;
  int u = nw == d[1] ? m + 1 : x;
  for (int i = (1); i <= (m); i++)
    if (w[i] == nw && x != i) {
      oo = f[nt[i]] + W(x, i) + (nt[i] > i ? m - nt[i] + i : i - nt[i]);
      if (oo < f[x]) f[x] = oo, to[u] = {i, nt[i]};
      oo = f[ls[i]] + W(x, i) + (ls[i] >= i ? ls[i] - i : m - i + ls[i]);
      if (oo < f[x]) f[x] = oo, to[u] = {i, -ls[i]};
    }
}
void find(int nw) {
  pair<int, int> y = nw == d[1] ? to[m + 1] : to[s];
  int u = abs(y.second);
  c[y.first] = y.second > 0;
  s = y.first;
  if (c[s]) {
    for (int i = (s); i >= (1); i--)
      if (w[i] == nw && (i != k || i == k && nw != d[1])) as[++tt] = i;
    for (int i = (m); i >= (s + 1); i--)
      if (w[i] == nw && (i != k || i == k && nw != d[1])) as[++tt] = i;
  } else {
    for (int i = (s); i <= (m); i++)
      if (w[i] == nw && (i != k || i == k && nw != d[1])) as[++tt] = i;
    for (int i = (1); i <= (s - 1); i++)
      if (w[i] == nw && (i != k || i == k && nw != d[1])) as[++tt] = i;
  }
  s = u;
}
int main() {
  scanf("%d%d", &n, &s);
  m = n;
  for (int i = (1); i <= (n); i++) scanf("%d", &w[i]), a[i] = {w[i], i};
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n); i++)
    if (a[i].first == a[1].first && a[i].second == s) {
      as[++tt] = s;
      for (int j = (i); j <= (n - 1); j++) a[j] = a[j + 1];
      n--;
    }
  for (int i = (1); i <= (n); i++) {
    ct++;
    d[ct] = a[i].first;
    k = i;
    for (int j = (i); j <= (n); j++)
      if (a[i].first != a[j].first)
        break;
      else
        i = j, v[ct].push_back(a[j].second);
    for (int j = (k); j <= (i); j++) {
      ls[a[j].second] = j != k ? a[j - 1].second : a[i].second;
      nt[a[j].second] = j != i ? a[j + 1].second : a[k].second;
    }
  }
  v[0].push_back(s);
  for (int i = (ct - 1); i >= (0); i--)
    for (int y : v[i]) sol(y, d[i + 1]);
  k = s;
  printf("%d\n", f[s]);
  for (int i = (0); i <= (ct - 1); i++) find(d[i + 1]);
  for (int i = (1); i <= (tt); i++) {
    s = as[i];
    if (s >= k)
      putchar(m - 2 * (s - k) > 0 ? '+' : '-');
    else
      putchar(m - 2 * (k - s) > 0 ? '-' : '+');
    printf("%d\n", W(s, k));
    k = as[i];
  }
}

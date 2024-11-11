#include <bits/stdc++.h>
using namespace std;
const int LEN = 1e6;
char s[LEN];
int n, _sa[LEN], _b[LEN], top[LEN], _tmp[LEN], LCP[LEN], *SA = _sa, *B = _b,
                                                         *tmp = _tmp;
void build_sa() {
  int na = (n < 256 ? 256 : n);
  for (int i = 0; i < n; ++i) top[B[i] = s[i]]++;
  for (int i = 1; i < na; ++i) top[i] += top[i - 1];
  for (int i = 0; i < n; ++i) SA[--top[B[i]]] = i;
  for (int ok = 1, j = 0; ok < n && j < n - 1; ok <<= 1) {
    for (int i = 0; i < n; ++i) {
      j = SA[i] - ok;
      if (j < 0) j += n;
      tmp[top[B[j]]++] = j;
    }
    SA[tmp[top[0] = 0]] = j = 0;
    for (int i = 1; i < n; ++i) {
      if (B[tmp[i]] != B[tmp[i - 1]] || B[tmp[i] + ok] != B[tmp[i - 1] + ok])
        top[++j] = i;
      SA[tmp[i]] = j;
    }
    swap(B, SA), swap(SA, tmp);
  }
}
void build_lcp() {
  for (int i = 0, k = 0; i < n; ++i) {
    if (B[i] == n - 1) continue;
    for (int j = SA[B[i] + 1]; s[i + k] == s[j + k]; ++k)
      ;
    LCP[B[i]] = k;
    if (k) --k;
  }
}
int pre[LEN];
int mini[4 * LEN];
void pull(int v) { mini[v] = min(mini[2 * v], mini[2 * v + 1]); }
void build(int v, int b, int e) {
  if (b == e) {
    mini[v] = pre[b];
    return;
  }
  int m = (b + e) >> 1;
  build(2 * v, b, m);
  build(2 * v + 1, m + 1, e);
  pull(v);
}
vector<int> E[3 * LEN];
long long query(int v, int b, int e, int l, int r) {
  if (b >= l && e <= r) {
    return mini[v];
  }
  int m = (b + e) >> 1;
  if (m >= r) return query(2 * v, b, m, l, r);
  if (m < l) return query(2 * v + 1, m + 1, e, l, r);
  int q1 = query(2 * v, b, m, l, r);
  int q2 = query(2 * v + 1, m + 1, e, l, r);
  return min(q1, q2);
}
long long sol(long long val, int a, int b) {
  return upper_bound(E[val + LEN].begin(), E[val + LEN].end(), b) -
         lower_bound(E[val + LEN].begin(), E[val + LEN].end(), a);
}
long long solve(int a, int b) {
  if (s[a] != '(') return 0;
  a++, b++;
  int lo = a, hi = b;
  while (lo < hi) {
    int m = (lo + hi + 1) >> 1;
    if (query(1, 1, n, a, m) - pre[a - 1] >= 0) {
      lo = m;
    } else
      hi = m - 1;
  }
  return sol(pre[a - 1], a, lo);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    E[pre[i] + LEN].push_back(i);
  }
  build(1, 1, n);
  ++n;
  build_sa();
  build_lcp();
  --n;
  long long res = 0;
  for (int i = 1; i < n - 1; i++) {
    res += solve(SA[i], n - 1);
    if (LCP[i]) res -= solve(SA[i], SA[i] + LCP[i] - 1);
  }
  res += solve(SA[n - 1], n - 1);
  cout << res << '\n';
}

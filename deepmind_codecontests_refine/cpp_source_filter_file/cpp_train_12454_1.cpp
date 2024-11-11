#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, op = 1;
  while (ch < '0' || '9' < ch) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return op * x;
}
const int maxn = 1000009;
vector<int> a[maxn];
vector<long long> s[maxn];
int n, m, L[maxn], A[maxn], H[maxn], flag[maxn], p, q, tmp;
long long ans, res;
long long calc(int time, int A, int S) {
  if (s[A].empty()) {
    s[A].push_back(0);
    for (int i = 1; i < a[A].size(); i++) s[A].push_back(s[A].back() + a[A][i]);
  }
  tmp = upper_bound(a[A].begin(), a[A].end(), S) - a[A].begin() - 1;
  if (tmp >= 0)
    res = 1LL * S * (tmp + 1) - s[A][tmp];
  else
    res = 0;
  if (flag[A] == time) {
    a[A].clear();
    s[A].clear();
  }
  return res;
}
int main() {
  n = read();
  m = read();
  for (int i = 2; i <= n; i++) L[i] = read();
  for (int i = 1; i <= m; i++) {
    A[i] = read();
    H[i] = read();
    p = A[i];
    flag[A[i]] = i;
    while (p >= 2) {
      flag[p ^ 1] = i;
      p >>= 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    a[i].push_back(0);
    p = q = 0;
    while ((i << 1) <= n && p < a[(i << 1)].size() ||
           (i << 1 | 1) <= n && q < a[(i << 1 | 1)].size())
      if ((i << 1) <= n && p < a[(i << 1)].size() &&
          ((i << 1 | 1) > n || q == a[(i << 1 | 1)].size() ||
           a[(i << 1)][p] + L[(i << 1)] < a[(i << 1 | 1)][q] + L[(i << 1 | 1)]))
        a[i].push_back(a[(i << 1)][p++] + L[(i << 1)]);
      else
        a[i].push_back(a[(i << 1 | 1)][q++] + L[(i << 1 | 1)]);
    if ((i << 1) <= n && !flag[(i << 1)]) a[(i << 1)].clear();
    if ((i << 1 | 1) <= n && !flag[(i << 1 | 1)]) a[(i << 1 | 1)].clear();
  }
  for (int i = 1; i <= m; i++) {
    p = A[i];
    q = H[i];
    ans = calc(i, p, q);
    q -= L[p];
    while (p >= 2 && q > 0) {
      if ((p ^ 1) <= n && q - L[p ^ 1] > 0) ans += calc(i, p, q - L[p ^ 1]);
      ans += q;
      p >>= 1;
      q -= L[p];
    }
    printf("%I64d\n", ans);
  }
  return 0;
}

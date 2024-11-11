#include <bits/stdc++.h>
using namespace std;
int gi() {
  int ret = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}
const int N = (int)1e6 + 10;
const int mo = (int)1e9 + 7;
int n, k, a[N], l[N], r[N];
stack<pair<int, int> > S;
long long cal(int l, int r) {
  if (l > r) return 0;
  if (r - l + 1 - k < 0) return 0;
  int m = (r - l + 2 - k) / (k - 1);
  long long ret = 1ll * (m + 1) * (r - l + 2 - k) % mo -
                  1ll * (1 + m) * m / 2 % mo * (k - 1) % mo;
  return ret;
}
int main() {
  n = gi();
  k = gi();
  for (int i = 1; i <= n; i++) a[i] = gi();
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      S.push(make_pair(a[1], 1)), l[1] = 1;
    else {
      l[i] = i;
      while (S.size() && S.top().first < a[i]) l[i] = S.top().second, S.pop();
      S.push(make_pair(a[i], l[i]));
    }
  }
  while (S.size()) S.pop();
  for (int i = n; i >= 1; i--) {
    if (i == n)
      S.push(make_pair(a[n], n)), r[n] = n;
    else {
      r[i] = i;
      while (S.size() && S.top().first <= a[i]) r[i] = S.top().second, S.pop();
      S.push(make_pair(a[i], r[i]));
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long res = cal(l[i], r[i]) - cal(l[i], i - 1) - cal(i + 1, r[i]);
    res = res % mo * a[i] % mo;
    (ans += res) %= mo;
  }
  if (ans < 0) ans += mo;
  printf("%lld\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int oo = 2000000000;
const int N = 300005;
const int MOD = 1000000007;
pair<int, int> a[N];
int b[N], c[N], n, m, ft[N];
bool cmp(pair<int, int> u, pair<int, int> v) { return u.second < v.second; }
void nen() {
  sort(b + 1, b + b[0] + 1);
  for (int i = 1; i <= b[0]; ++i)
    if (i == 1 || b[i] != b[i - 1]) c[++c[0]] = b[i];
  for (int i = 1; i <= m; ++i) {
    a[i].first = lower_bound(c + 1, c + c[0] + 1, a[i].first) - c;
    a[i].second = lower_bound(c + 1, c + c[0] + 1, a[i].second) - c;
  }
}
void update(int x, int k) {
  for (; x <= c[0]; x += x & -x) ft[x] = (ft[x] + k) % MOD;
}
int retrieve(int x) {
  int res = 0;
  for (; x; x -= x & -x) res = (res + ft[x]) % MOD;
  if (res < 0) res += MOD;
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  b[++b[0]] = 0;
  b[++b[0]] = n;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
    b[++b[0]] = a[i].first;
    b[++b[0]] = a[i].second;
  }
  nen();
  n = lower_bound(c + 1, c + c[0] + 1, n) - c;
  sort(a + 1, a + m + 1, cmp);
  update(lower_bound(c + 1, c + c[0] + 1, 0) - c, 1);
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    int j = retrieve(a[i].second - 1), j2 = retrieve(a[i].first - 1);
    int SL = j - j2;
    if (SL < 0) SL += MOD;
    if (a[i].second == n) res = (res + SL) % MOD;
    update(a[i].first, SL);
  }
  if (res < 0) res += MOD;
  printf("%d\n", res);
  return 0;
}

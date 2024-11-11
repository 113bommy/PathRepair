#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int p = 1000000007, inf = 100000000;
int pow(int a, int b, int c) {
  if (a == 0) return 0;
  int d = a, e = 1;
  while (b) {
    if (b & 1) e = (1LL * e * d) % c;
    d = 1LL * d * d % c;
    b >>= 1;
  }
  return e;
}
int random(int n) { return 1LL * rand() * rand() % n + 1; }
int n;
long long ans;
pair<int, int> a[N], b[N];
int l[N], r[N], ll[N], rr[N];
void calc(int kd) {
  int num = 0;
  for (int i = 1; i <= n; i++)
    if ((a[i].first + inf) % 2 == kd) b[++num] = a[i];
  l[0] = ll[num] = inf, r[0] = rr[num] = -inf;
  for (int i = 1; i <= num; i++) {
    l[i] = min(l[i - 1], b[i].second);
    r[i] = max(r[i - 1], b[i].second);
  }
  for (int i = num; i >= 1; i--) {
    ll[i - 1] = min(ll[i], b[i].second);
    rr[i - 1] = max(rr[i], b[i].second);
  }
  for (int i = 1; i < num; i++) {
    int x = (min(rr[i], r[i]) - max(ll[i], l[i])) / 2;
    int h = (b[i + 1].first - b[i].first) / 2;
    if (x > 0) ans += 1LL * x * h;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i].first, &a[i].second),
        a[i].first = a[i].first + a[i].second,
        a[i].second = a[i].first - 2 * a[i].second;
  sort(a + 1, a + 1 + n);
  ans = 0;
  calc(0);
  calc(1);
  cout << ans << endl;
  return 0;
}

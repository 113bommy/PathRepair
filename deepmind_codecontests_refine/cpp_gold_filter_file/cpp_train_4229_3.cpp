#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30);
int Rand() { return (rand() << 16) | rand(); }
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
long long sum, k;
int n, i, j, cur, f, r, _r;
pair<int, int> a[101010];
bool w[101010];
vector<int> b;
vector<pair<int, int> > c;
int main() {
  scanf("%d%I64d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    sum += a[i].first;
    a[i].second = i;
  }
  if (sum < k)
    printf("-1");
  else if (sum != k) {
    sort(a, a + n);
    for (i = 0; i < n; i++)
      if (!i || a[i].first != a[i - 1].first) {
        if (1ll * (a[i].first - cur) * (n - i) > k) {
          f = (k + n - i - 1) / (n - i);
          _r = r = k % (n - i);
          for (j = i; j < n; j++) c.push_back(a[j]);
          sort((c).begin(), (c).end(), cmp);
          for (j = 0; j < _r; j++)
            if (cur + f >= c[j].first) {
              c[j].first = 0;
              r--;
            }
          for (j = 0; j < (n - i); j++)
            if (c[j].first) {
              b.push_back(c[j].second);
              w[c[j].second] = 1;
            }
          break;
        }
        k -= 1ll * (a[i].first - cur) * (n - i);
        cur = a[i].first;
      }
    sort((b).begin(), (b).end());
    for (i = b[r]; i < n; i++)
      if (w[i]) printf("%d ", i + 1);
    for (i = 0; i < b[r]; i++)
      if (w[i]) printf("%d ", i + 1);
  }
  return 0;
}

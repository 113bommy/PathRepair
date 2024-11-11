#include <bits/stdc++.h>
int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dr1[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc1[] = {1, -1, 1, 0, -1, 0, 1, -1};
int dr2[] = {0, 0, 1, -1};
int dc2[] = {1, -1, 0, 0};
using namespace std;
long long int l[200005], pre[200005];
int main() {
  long long int n, k, q, m, i, x, y;
  while (cin >> n >> k >> q) {
    memset(l, 0, sizeof(l));
    memset(pre, 0, sizeof(pre));
    for (i = 0; i < n; i++) {
      scanf("%lld%lld", &x, &y);
      l[x] += 1;
      l[y + 1] = -1;
    }
    m = 0;
    for (i = 1; i <= 200000; i++) l[i] += l[i - 1];
    for (i = 1; i <= 200000; i++) {
      pre[i] = pre[i - 1];
      if (l[i] >= k) pre[i]++;
    }
    while (q--) {
      scanf("%lld%lld", &x, &y);
      cout << pre[y] - pre[x - 1] << endl;
    }
  }
  return 0;
}

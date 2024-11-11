#include <bits/stdc++.h>
using namespace std;
const int MaxN = 123456, Max = 2000000000;
int a[MaxN], b[MaxN];
vector<pair<int, int> > v;
int mxbf[MaxN], mxbb[MaxN], mnbf[MaxN], mnbb[MaxN];
int main(void) {
  int n = 100000;
  while (scanf("%d", &n) != EOF) {
    int i, j, x, y;
    int res = Max, l, r, m;
    v.clear();
    for (i = 0; i < n; i++) {
      scanf("%d %d", &x, &y);
      v.push_back(make_pair(x + y, x - y));
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++) a[i + 1] = v[i].first, b[i + 1] = v[i].second;
    mxbf[0] = mxbb[n + 1] = -1e9;
    mnbf[0] = mnbb[n + 1] = 1e9;
    mxbf[1] = mnbf[1] = b[1];
    for (i = 1; i <= n; i++)
      mnbf[i] = min(mnbf[i - 1], b[i]), mxbf[i] = max(mxbf[i - 1], b[i]);
    mxbb[n] = mnbb[n] = b[n];
    for (i = n - 1; i >= 1; i--)
      mnbf[i] = min(mnbf[i + 1], b[i]), mxbf[i] = max(mxbf[i + 1], b[i]);
    l = 0, r = Max;
    while (r - l > 0) {
      m = l + (r - l) / 2;
      bool ok = false;
      for (i = 0, j = 0; i < n; i++) {
        while (a[j] - a[i] <= m && j < n) j++;
        if (max(mxbf[i - 1], mxbb[j]) - min(mnbf[i - 1], mnbb[j]) <= m) {
          ok = true;
          break;
        }
      }
      if (ok)
        r = m;
      else
        l = m + 1;
    }
    res = l;
    printf("%.8lf\n", res * 0.5);
  }
}

#include <bits/stdc++.h>
using namespace std;
vector<int> x, y, x2, y2, h2, v2;
set<int> h, v;
vector<int> x3[1000005], y3[1000005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    h.clear();
    v.clear();
    x.clear();
    y.clear();
    x2.clear();
    y2.clear();
    h2.clear();
    v2.clear();
    int n, m, k, tmp;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tmp);
      h.insert(tmp);
      h2.push_back(tmp);
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &tmp);
      v.insert(tmp);
      v2.push_back(tmp);
    }
    int tmpx, tmpy;
    for (int i = 1; i <= k; i++) {
      scanf("%d%d", &tmpx, &tmpy);
      x.push_back(tmpx);
      y.push_back(tmpy);
      x2.push_back(tmpx);
      y2.push_back(tmpy);
      x3[tmpx].push_back(tmpy);
      y3[tmpy].push_back(tmpx);
    }
    sort(x2.begin(), x2.end());
    sort(y2.begin(), y2.end());
    for (int i : h2) {
      sort(x3[i].begin(), x3[i].end());
    }
    for (int i : v2) {
      sort(y3[i].begin(), y3[i].end());
    }
    vector<int>::iterator it1, it2;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      tmpx = x[i], tmpy = y[i];
      int f1 = 0, f2 = 0;
      if (h.find(tmpx) != h.end()) f1 = 1;
      if (v.find(tmpy) != v.end()) f2 = 1;
      if (f1 && f2) continue;
      if (f1) {
        it1 = upper_bound(v2.begin(), v2.end(), tmpy);
        it1--;
        it2 = lower_bound(v2.begin(), v2.end(), tmpy);
        if (*it1 >= *it2) continue;
        int l = upper_bound(y2.begin(), y2.end(), *it1) - y2.begin() - 1;
        int r = lower_bound(y2.begin(), y2.end(), *it2) - y2.begin() - 1;
        ans += r - l;
        l = upper_bound(x3[tmpx].begin(), x3[tmpx].end(), *it1) -
            x3[tmpx].begin() - 1;
        r = lower_bound(x3[tmpx].begin(), x3[tmpx].end(), *it2) -
            x3[tmpx].begin() - 1;
        ans -= r - l;
      } else {
        it1 = upper_bound(h2.begin(), h2.end(), tmpx);
        it1--;
        it2 = lower_bound(h2.begin(), h2.end(), tmpx);
        if (*it1 >= *it2) continue;
        int l = upper_bound(x2.begin(), x2.end(), *it1) - x2.begin() - 1;
        int r = lower_bound(x2.begin(), x2.end(), *it2) - x2.begin() - 1;
        ans += r - l;
        l = upper_bound(y3[tmpy].begin(), y3[tmpy].end(), *it1) -
            y3[tmpy].begin() - 1;
        r = lower_bound(y3[tmpy].begin(), y3[tmpy].end(), *it2) -
            y3[tmpy].begin() - 1;
        ans -= r - l;
      }
    }
    ans /= 2;
    printf("%lld\n", ans);
    for (int i : x) {
      x3[i].clear();
    }
    for (int i : y) {
      y3[i].clear();
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int oo = 0x3f3f3f3f;
pair<long long, long long> a[maxn];
priority_queue<long long> q;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%I64d %I64d", &a[i].first, &a[i].second);
    }
    sort(a + 2, a + 1 + n);
    reverse(a + 2, a + 1 + n);
    int r = 2;
    while (r <= n && a[r].first > a[1].first) {
      q.push(-(a[r].second - a[r].first + 1));
      ++r;
    }
    int ret = r - 1, f = 1;
    while (!q.empty()) {
      long long tmp = -q.top();
      q.pop();
      a[1].first -= tmp;
      if (a[1].first < 0) break;
      ++f;
      while (r <= n && a[r].first > a[1].first) {
        q.push(-(a[r].second - a[r].first + 1));
        ++r;
      }
      ret = min(ret, r - f);
    }
    printf("%d\n", ret);
  }
}

#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long llinf = (long long)1e15;
const int N = (int)1e5 + 111;
const long double PI = (long double)acos(-1);
int main() {
  int n, m, i;
  scanf("%d %d", &n, &m);
  vector<int> s(m), d(m), c(m);
  vector<int> ans(n, 0);
  vector<pair<int, int> > arr(m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &s[i], &d[i], &c[i]);
    s[i]--;
    d[i]--;
    arr[i].first = d[i];
    arr[i].second = i;
  }
  sort(arr.begin(), arr.end());
  for (int j = 0; j < m; j++) {
    i = arr[j].second;
    if (ans[d[i]] == 0)
      ans[d[i]] = m + 1;
    else {
      printf("-1");
      return 0;
    }
    for (int ii = s[i]; ii < d[i] && c[i] != 0; ii++) {
      if (ans[ii] != 0) continue;
      ans[ii] = i + 1;
      c[i]--;
    }
    if (c[i] != 0) {
      printf("-1");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}

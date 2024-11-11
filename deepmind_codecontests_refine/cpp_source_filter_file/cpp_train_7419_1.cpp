#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int n, m, a[500005];
pair<int, int> w[500005];
vector<int> o, vec[500005];
int cnt[500005];
priority_queue<int, vector<int>, greater<int> > q;
void work() {
  n = read(), o.clear();
  for (register int i = (1); i <= (n); ++i) vec[i].clear(), cnt[i] = 0;
  for (register int i = (1); i <= (n); ++i) {
    a[i] = read();
    if (!a[i]) o.push_back(i);
  }
  if (o.size() < 2) {
    puts("0");
    return;
  }
  int m = o.size(), mid = m / 2;
  for (register int i = (1); i <= (n); ++i) w[i] = make_pair(0, mid + 1);
  int now = 0;
  for (register int i = (1); i <= (n); ++i) {
    if (a[i]) {
      if (i < o[mid])
        w[a[i]].first = max(w[a[i]].first, now);
      else
        w[a[i]].second = min(w[a[i]].second, now);
    } else if (i == o[mid])
      now = 2 - m % 2;
    else
      now++;
  }
  int res = 0;
  for (register int i = (1); i <= (n); ++i) {
    if (w[i].first + 1 >= w[i].second)
      res++;
    else if (w[i].first > 0 || w[i].second <= mid)
      vec[w[i].first].push_back(w[i].second);
  }
  now = 0;
  int M = 0;
  for (int x = 0; x <= mid; vec[x].clear(), ++x)
    for (int y : vec[x])
      if (q.emplace(y), M < x)
        ++M;
      else
        ++cnt[q.top()], q.pop();
  res += now;
  for (int i = 1, j = mid; j >= 0; --j, ++i) {
    now = min(cnt[j], i);
    i -= now;
    res += now;
  }
  while (q.size()) q.pop();
  cout << min(res, mid) << endl;
}
signed main() {
  int T = read();
  while (T--) work();
  return 0;
}

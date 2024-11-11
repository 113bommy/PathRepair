#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, buf[100001], pat[100001];
vector<int> vec[100001], ex, t;
bool check(long double pos) {
  for (int i = 1; i <= n; i++)
    buf[i] = vec[i].size(), pat[i] = ceil(buf[i] * pos);
  queue<int> s;
  for (int i : ex) s.push(i), buf[i] = 1e7;
  while (!s.empty()) {
    for (int i : vec[s.front()]) {
      if (--buf[i] < pat[i]) s.push(i), buf[i] = 1e7;
    }
    s.pop();
  }
  t.clear();
  for (int i = 1; i < n + 1; i++)
    if (buf[i] < 1e5 + 1) t.push_back(i);
  return t.size();
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> x;
    ex.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  double st = 0, en = 1, mid = (st + en) / 2;
  while (en - st > 1e-12) {
    (check(mid) ? st : en) = mid;
    mid = (st + en) / 2;
  }
  check((mid - 1e-12));
  printf("%d\n", t.size());
  for (int i = 0; i < t.size(); i++) {
    if (i) printf(" ");
    printf("%d", t[i]);
  }
  puts("");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9;
const int N = 100010;
int n, m, p, q;
int f[N];
long long w[N];
set<pair<long long, int> > s;
int find_set(int x) {
  if (f[x] == x) return x;
  return f[x] = find_set(f[x]);
}
int main() {
  scanf("%d %d %d %d", &n, &m, &p, &q);
  for (int i = 1; i <= n; ++i) f[i] = i, w[i] = 0;
  for (int i = 0, x, y, l; i < m; ++i) {
    scanf("%d %d %d", &x, &y, &l);
    x = find_set(x), y = find_set(y);
    if (x == y)
      w[x] += l;
    else {
      f[x] = y;
      w[y] += w[x] + l;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (f[i] == i) s.insert(make_pair(w[i], i));
  }
  int fp = s.size();
  vector<pair<int, int> > ans;
  if (fp - p > q or fp < q)
    puts("NO");
  else {
    for (int i = 0; i < fp - q; ++i) {
      pair<long long, int> u = *s.begin();
      s.erase(s.begin());
      pair<long long, int> v = *s.begin();
      s.erase(s.begin());
      ans.push_back(make_pair(u.second, v.second));
      s.insert(make_pair(u.first + v.first + min(inf, u.first + v.first + 1),
                         u.second));
      f[u.second] = v.second;
    }
    int x = -1;
    for (int i = 1; i <= n; ++i)
      if (f[i] != i) x = i;
    if (p - (fp - q) and x == -1) {
      puts("NO");
      return 0;
    }
    for (int i = 0; i < p - (fp - q); ++i) ans.push_back(make_pair(x, f[x]));
    puts("YES");
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}

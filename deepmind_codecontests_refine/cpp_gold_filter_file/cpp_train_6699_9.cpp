#include <bits/stdc++.h>
using namespace std;
void compress(vector<pair<int, int> >& a) {
  vector<int> b(a.size() * 2);
  for (int i = 0; i < a.size(); i++)
    b[i * 2] = a[i].first, b[i * 2 + 1] = a[i].second;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  map<int, int> tmp;
  for (int i = 0; i < b.size(); i++) tmp[b[i]] = i;
  for (int i = 0; i < a.size(); i++)
    a[i].first = tmp[a[i].first], a[i].second = tmp[a[i].second];
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
  compress(a);
  vector<pair<int, int> > cnt(3 * n, make_pair(0, 0));
  for (int i = 0; i < n; i++) {
    cnt[a[i].first].first++;
    if (a[i].second != a[i].first) cnt[a[i].second].second++;
  }
  int res = 1e9;
  for (int i = 0; i < cnt.size(); i++) {
    if (cnt[i].first + cnt[i].second >= (n + 1) / 2)
      res = min(res, max((n + 1) / 2 - cnt[i].first, 0));
  }
  if (res == 1e9) res = -1;
  printf("%d\n", res);
  return 0;
}

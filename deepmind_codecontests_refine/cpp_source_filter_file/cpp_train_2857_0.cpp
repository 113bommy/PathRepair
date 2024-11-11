#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
set<pair<int, int> > o, t;
int a[300009], b[300009], ans[300009];
int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    o.insert(make_pair(a[i], i));
    t.insert(make_pair(b[i], i));
  }
  long long res = 0;
  while (w >= 1) {
    if (w & 1 or !t.size() or o.size() == 1) {
      int i = (*o.begin()).second;
      o.erase(make_pair(a[i], i));
      res += a[i] + 0LL;
      t.erase(make_pair(b[i], i));
      if (!ans[i]) {
        a[i] = b[i] - a[i];
        o.insert(make_pair(a[i], i));
      }
      ans[i]++, w--;
    } else {
      pair<int, int> i = *o.begin();
      pair<int, int> j = *(++o.begin());
      pair<int, int> k = *t.begin();
      if (i.first + j.first < k.first) {
        res += a[i.second] + 0LL;
        res += a[j.second] + 0LL;
        o.erase(make_pair(a[i.second], i.second));
        t.erase(make_pair(b[i.second], i.second));
        if (!ans[i.second]) {
          a[i.second] = b[i.second] - a[i.second];
          o.insert(make_pair(a[i.second], i.second));
        }
        ans[j.second]++, w--;
        o.erase(make_pair(a[j.second], j.second));
        t.erase(make_pair(b[j.second], j.second));
        if (!ans[j.second]) {
          a[j.second] = b[j.second] - a[j.second];
          o.insert(make_pair(a[j.second], j.second));
        }
        ans[j.second]++, w--;
      } else {
        res += b[k.second] + 0LL;
        o.erase(make_pair(a[k.second], k.second));
        t.erase(make_pair(b[k.second], k.second));
        ans[k.second] = 2;
        w -= 2;
      }
    }
  }
  printf("%lld\n", res);
  for (int i = 1; i <= n; i++) printf("%d", ans[i]);
  return 0;
}

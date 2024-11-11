#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100010;
int n, m, k;
map<int, vector<pair<int, int> > > a, b;
int s = 0;
void deal(map<int, vector<pair<int, int> > > &a, int n, int m) {
  if ((m + 1 - a.size()) % 2) s ^= n;
  for (map<int, vector<pair<int, int> > >::iterator it = a.begin();
       it != a.end(); ++it) {
    sort(it->second.begin(), it->second.end());
    vector<pair<int, int> > v;
    pair<int, int> p = it->second[0];
    for (int i = 1; i < it->second.size(); ++i) {
      if (it->second[i].first > p.second) {
        v.push_back(p);
        p = it->second[i];
      } else
        p.second = max(p.second, it->second[i].second);
    }
    v.push_back(p);
    it->second = v;
    int t = 0;
    for (int i = 0; i < v.size(); ++i) t += v[i].second - v[i].first;
    s ^= n - t;
  }
}
int search(vector<pair<int, int> > &v, int L, int R, int get) {
  int ans = R;
  while (L <= R) {
    int m = (L + R) >> 1;
    int t = m;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i].first >= m)
        t += v[i].second - v[i].first;
      else if (v[i].second >= m)
        t += v[i].second - m;
    }
    if (t >= get) {
      ans = m;
      R = m - 1;
    } else
      L = m + 1;
  }
  return ans;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      a[x1].push_back(pair<int, int>(y1, y2));
    } else if (y1 == y2) {
      if (x1 > x2) swap(x1, x2);
      b[y1].push_back(pair<int, int>(x1, x2));
    }
  }
  deal(a, m, n);
  deal(b, n, m);
  if (s) {
    puts("FIRST");
    if (a.size() < n)
      for (int i = 1; i <= n; ++i) {
        if (!a.count(i)) {
          a[i];
          break;
        }
      }
    for (map<int, vector<pair<int, int> > >::iterator it = a.begin();
         it != a.end(); ++it) {
      vector<pair<int, int> > v = it->second;
      int t = 0;
      for (int i = 0; i < v.size(); ++i) t += v[i].second - v[i].first;
      t = m - t;
      if (!t) continue;
      if ((s ^ t) >= t) continue;
      int p = search(v, 0, m, m - (s ^ t));
      printf("%d %d %d %d\n", it->first, 0, it->first, p);
      return 0;
    }
    if (b.size() < m)
      for (int i = 1; i <= m; ++i) {
        if (!b.count(i)) {
          b[i];
          break;
        }
      }
    for (map<int, vector<pair<int, int> > >::iterator it = b.begin();
         it != b.end(); ++it) {
      vector<pair<int, int> > v = it->second;
      int t = 0;
      for (int i = 0; i < v.size(); ++i) t += v[i].second - v[i].first;
      t = n - t;
      if (!t) continue;
      if ((s ^ t) >= t) continue;
      int p = search(v, 0, n, n - (s ^ t));
      printf("%d %d %d %d\n", 0, it->first, p, it->first);
      return 0;
    }
  } else {
    puts("SECOND");
  }
  return 0;
}

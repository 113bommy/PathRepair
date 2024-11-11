#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
set<int> v[N], d1;
int d[N];
bool vis[N];
int main() {
  int n, k, x, y;
  cin >> n >> k;
  int c2 = 0, c3 = 0;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    v[x].insert(y);
    v[y].insert(x);
    d[x]++;
    d[y]++;
    if (d[x] == 1) d1.insert(x);
    if (d[x] == 2) d1.erase(x), c2++;
    if (d[x] == 3) c2--, c3++;
    if (d[y] == 1) d1.insert(y);
    if (d[y] == 2) d1.erase(y), c2++;
    if (d[y] == 3) c2--, c3++;
  }
  if (k >= n || n <= 3 || c2 || !c3) return cout << "No", 0;
  while (--k) {
    if (d1.size() == 0) return cout << "No", 0;
    set<int> t;
    set<pair<int, int> > temp;
    for (int x : d1) {
      y = *v[x].begin();
      d[y]--;
      pair<int, int> p = {y, 1};
      if (temp.lower_bound(p) != temp.end() &&
          temp.lower_bound(p)->first == y) {
        p.second = temp.lower_bound(p)->second;
        p.second++;
        temp.erase({p.first, p.second - 1});
        temp.insert(p);
      } else
        temp.insert(p);
      if (d[y] == 0) return cout << "No", 0;
      if (d[y] == 1) c2--, t.insert(y);
      if (d[y] == 2) c2++, c3--;
      v[y].erase(x);
    }
    for (auto x : temp) {
      if (x.second <= 2) return cout << "No", 0;
    }
    d1 = t;
    t.erase(t.begin(), t.end());
  }
  if (c2 || !c3) return cout << "No", 0;
  cout << "Yes";
  return 0;
}

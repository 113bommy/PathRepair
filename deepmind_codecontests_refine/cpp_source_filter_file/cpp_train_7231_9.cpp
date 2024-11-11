#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int n, m, cnt, match[N];
struct Node {
  int a, b, c, id;
  bool operator<(Node const &other) const {
    if (a == other.a) {
      if (b == other.b)
        return c > other.c;
      else
        return b > other.c;
    } else
      return a < other.a;
  }
} all[N << 1];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> all[i].a >> all[i].b;
    all[i].c = 0;
    all[i].id = i + 1;
  }
  cin >> m;
  for (int i = n, ed = n + m; i < ed; i++) {
    cin >> all[i].a >> all[i].b >> all[i].c;
    all[i].id = i - n + 1;
  }
  sort(all, all + n + m);
  map<pair<int, int>, int> cache;
  for (int i = 0, ed = n + m; i < ed; i++) {
    if (all[i].c)
      cache[pair<int, int>(all[i].b, all[i].id)] = all[i].c;
    else {
      map<pair<int, int>, int>::iterator it =
          cache.lower_bound(pair<int, int>(all[i].b, 0));
      if (it == cache.end()) {
        cout << "NO" << endl;
        return 0;
      }
      match[all[i].id] = it->first.second;
      if (it->second == 1)
        cache.erase(it);
      else
        it->second--;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) printf("%d%c", match[i], i == n ? '\n' : ' ');
  return 0;
}

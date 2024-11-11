#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> fromCord;
map<int, pair<int, int> > fromIndex;
int canRemove(int x, int y) {
  for (int i = (-1); i < (2); i += (1)) {
    int p = x + i, q = y + 1;
    if (fromCord.find(make_pair(p, q)) == fromCord.end()) continue;
    int hai = 0;
    for (int j = (-1); j < (2); j += (1)) {
      int a = p + j, b = y;
      if (a != x && fromCord.find(make_pair(a, b)) != fromCord.end()) {
        hai = 1;
        break;
      }
    }
    if (!hai) {
      return 0;
    }
  }
  return 1;
}
set<int> s;
int main() {
  int n = ({
    int x;
    scanf("%d", &x);
    x;
  });
  for (int i = (0); i < (n); i += (1)) {
    int x = ({
      int x;
      scanf("%d", &x);
      x;
    }),
        y = ({
          int x;
          scanf("%d", &x);
          x;
        });
    fromCord[make_pair(x, y)] = i;
    fromIndex[i] = make_pair(x, y);
  }
  for (int k = (0); k < (n); k += (1)) {
    int x = fromIndex[k].first, y = fromIndex[k].second;
    if (canRemove(x, y)) {
      s.insert(k);
    }
  }
  int bit = 1;
  int ans = 0;
  while (!s.empty()) {
    int num;
    if (bit) {
      num = *(s.rbegin());
    } else {
      num = *(s.begin());
    }
    ans = (ans * (long long)n + num) % 1000000009;
    bit ^= 1;
    int x = fromIndex[num].first, y = fromIndex[num].second;
    s.erase(num);
    fromIndex.erase(num);
    fromCord.erase(make_pair(x, y));
    for (int j = (-1); j < (2); j += (2)) {
      for (int i = (-1); i < (2); i += (1)) {
        if (fromCord.find(make_pair(x + i, y + j)) == fromCord.end()) continue;
        int can_remove = canRemove(x + i, y + j);
        if (can_remove)
          s.insert(fromCord[make_pair(x + i, y + j)]);
        else
          s.erase(fromCord[make_pair(x + i, y + j)]);
      }
    }
  }
  cout << ans;
}

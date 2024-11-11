#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  char str[1000001];
  scanf("%d %d %s", &n, &k, &str);
  map<char, pair<int, int> > m;
  int i = 0;
  while (str[i]) {
    if (m.find(str[i]) != m.end()) {
      m[str[i]].second = i;
    } else {
      m[str[i]].first = i;
    }
    i++;
  }
  int r = 0;
  set<int> s, e;
  for (auto it = m.begin(); it != m.end(); it++) {
    s.insert(it->second.first);
    e.insert(it->second.second);
  }
  for (auto it = s.begin(); it != s.end(); it++) {
    bool f = 0;
    for (auto it2 = e.begin(); it2 != e.end(); it2++) {
      if (*it > *it2) {
        f = 1;
        e.erase(it2);
        break;
      }
    }
    if (!f) r++;
  }
  puts((r > k) ? "YES" : "NO");
  return 0;
}

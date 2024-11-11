#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int x[N], y[N], w[N], s[N], v[N];
vector<pair<int, int> > e[N];
vector<int> res;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++) {
    scanf("%d%d", x + i, y + i);
    w[i] = 1;
    s[x[i]]++;
    s[y[i]]++;
    e[max(x[i], y[i])].push_back(make_pair(min(x[i], y[i]), i));
  }
  for (int i = (1); i <= (n); i++) {
    set<int> in;
    for (auto it : e[i]) {
      if (!v[it.first]) {
        v[it.first] = 1;
        w[it.second] = 0;
        s[i]--;
      }
      in.insert(s[it.first]);
    }
    while (e[i].size()) {
      if (in.find(s[i]) == in.end()) break;
      s[i]++;
      v[e[i].back().first] = 0;
      w[e[i].back().second]++;
      e[i].pop_back();
    }
    if (in.find(s[i]) != in.end()) {
      s[i]++;
      v[i] = 1;
    }
  }
  for (int i = (1); i <= (n); i++)
    if (v[i]) res.push_back(i);
  printf("%d\n", int(res.size()));
  for (auto it : res) printf("%d ", it);
  puts("");
  for (int i = (1); i <= (m); i++) printf("%d %d %d\n", x[i], y[i], w[i]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, s[101000], r[101000];
vector<int> g[101000];
long long rec(int at, int pre) {
  vector<long long> v;
  for (int i = 0; i < g[at].size(); i++)
    if (g[at][i] != pre && r[g[at][i]] > 0) {
      r[g[at][i]]--;
      v.push_back(rec(g[at][i], at));
    }
  long long cur = 0;
  if (r[at] < (int)v.size()) {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < r[at]; i++) cur += v[i] + 2;
    r[at] = 0;
  } else {
    for (int i = 0; i < v.size(); i++) cur += v[i] + 2;
    r[at] -= v.size();
    for (int i = 0; i < g[at].size(); i++)
      if (g[at][i] != pre) {
        long long df = min(r[at], r[g[at][i]]);
        r[at] -= df;
        cur += df;
      }
  }
  return cur;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", s + i);
  for (int i = 0; i < n; i++) r[i] = s[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int st;
  scanf("%d", &st);
  cout << rec(st - 1, -1) << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int const N = 1e3 + 5;
int const NN = 8;
int deploy[N], test[N], n, ok[NN];
int ct[N], use[N];
int que[N];
vector<pair<int, int> > ans;
vector<int> pos[N];
int count(int x) {
  int res = 0;
  while (x) {
    res++;
    x -= x & (-x);
  }
  return res;
}
bool cmp(int p, int q) { return deploy[p] < deploy[q]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      int x;
      cin >> x;
      deploy[i] |= (1 << j) * x;
    }
    pos[deploy[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      int x;
      cin >> x;
      test[i] |= (1 << j) * x;
    }
  }
  int top = 0, bot = 1;
  que[++top] = 1;
  while (bot <= top) {
    int u = que[bot];
    bot++;
    int mask = deploy[u] & test[u];
    ct[u] = 1;
    use[u] = 1;
    if (ok[mask]) {
      continue;
    }
    ok[mask] = u;
    for (int p : pos[mask]) {
      que[++top] = p;
      if (u != p) {
        ans.push_back(make_pair(u, p));
      }
    }
  }
  vector<int> rest;
  for (int i = 1; i <= n; i++) {
    if (use[i]) {
      continue;
    }
    rest.push_back(i);
  }
  sort(rest.begin(), rest.end(), cmp);
  for (int i = 0; i < rest.size();) {
    int pos = i;
    while (pos < rest.size() && deploy[rest[i]] == deploy[rest[pos]]) {
      pos++;
    }
    for (int j = i + 1; j < pos; j++) {
      ans.push_back(make_pair(rest[j - 1], rest[j]));
    }
    int u = rest[i];
    if (count(deploy[u]) == 1) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (count(deploy[u]) == 0) {
      i = pos;
      continue;
    }
    for (int j = 0; j < 3; j++) {
      if ((deploy[u] >> j) & 1) {
        if (ok[1 << j] == 0) {
          cout << "Impossible" << endl;
          return 0;
        }
        ans.push_back(make_pair(ok[1 << j], rest[i]));
        ct[ok[1 << j]] = 1;
      }
    }
    i = pos;
  }
  cout << "Possible" << endl;
  for (int i = 1; i <= n; i++) {
    cout << ct[i] << " ";
  }
  cout << endl;
  cout << ans.size() << endl;
  for (pair<int, int> p : ans) {
    cout << p.first << " " << p.second << endl;
  }
}

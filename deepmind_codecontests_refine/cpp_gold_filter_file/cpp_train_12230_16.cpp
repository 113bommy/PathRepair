#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;
struct __timestamper {};
vector<vector<pair<int, int>>> rests;
int n;
vector<int> rig, spl;
vector<int> ans;
void restore(int v) {
  if (v + 1 < spl[v]) {
    rig[v + 1] = spl[v] - 1;
    restore(v + 1);
  }
  ans.push_back(v);
  if (spl[v] <= rig[v]) {
    rig[spl[v]] = rig[v];
    restore(spl[v]);
  }
}
bool check() {
  rig = vector<int>(n);
  for (int i = 0; i < (n); i++) rig[i] = i;
  spl = vector<int>(n);
  for (int i = n - 1; i >= 0; i--) {
    for (pair<int, int> r : rests[i]) {
      if (r.first <= i) return false;
      rig[i] = max(rig[i], rig[r.first]);
    }
    for (int i2 = i; i2 <= rig[i]; i2++) rig[i] = max(rig[i], rig[i2]);
    vector<pair<int, int>> seq;
    for (int i2 = i + 1; i2 <= rig[i];) {
      seq.push_back(make_pair(i2, rig[i2]));
      i2 = rig[i2] + 1;
    }
    int b1 = 0, b2 = ((int)(seq).size());
    for (pair<int, int> r : rests[i]) {
      int id = upper_bound(seq.begin(), seq.end(), make_pair(r.first, inf)) -
               seq.begin() - 1;
      if (r.second == 0) {
        b1 = max(b1, id + 1);
      } else {
        b2 = min(b2, id);
      }
    }
    if (b1 > b2) return false;
    if (seq.empty()) {
      spl[i] = i + 1;
    } else {
      spl[i] = b1 == ((int)(seq).size()) ? rig[i] + 1 : seq[b1].first;
    }
  }
  ans.clear();
  rig[0] = n - 1;
  restore(0);
  for (int i = 0; i < (n); i++) printf("%d%c", ans[i] + 1, "\n "[i + 1 < n]);
  return true;
}
int main() {
  int m;
  while (scanf("%d%d", &n, &m) == 2) {
    rests = vector<vector<pair<int, int>>>(n);
    for (int i = 0; i < (m); i++) {
      int a, b;
      char ty[10];
      scanf("%d%d%s", &a, &b, ty), a--, b--;
      rests[a].push_back(make_pair(b, !strcmp(ty, "LEFT") ? 0 : 1));
    }
    if (!check()) {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}

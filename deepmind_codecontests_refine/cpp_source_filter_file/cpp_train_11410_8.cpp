#include <bits/stdc++.h>
using namespace std;
typedef struct {
  bool b;
  int k;
  vector<int> to;
} T1;
T1 G[100010];
int s;
long long f(int pred = 0, int v = s) {
  if (G[v].k == 0) return (0);
  long long res = 0;
  vector<int>& to = G[v].to;
  vector<int> tmp;
  for (int i = 0; i < to.size(); i++) {
    int _v = to[i];
    bool b = G[_v].b;
    int k = G[_v].k;
    if (!b && (k > 0)) {
      G[_v].b = true;
      G[_v].k--;
      tmp.push_back(f(v, _v) + 1);
    }
  }
  sort(tmp.begin(), tmp.end(), greater<int>());
  int i = 0;
  while (G[v].k > 0 && i < tmp.size()) {
    res += tmp[i] + 1;
    i++;
    G[v].k--;
  }
  if (G[v].k == 0) return (res);
  for (int i = 0; i < to.size(); i++) {
    int _v = to[i];
    int k = G[_v].k;
    if (_v == pred) continue;
    res += 2 * min(G[v].k, G[_v].k);
    G[v].k -= min(G[v].k, G[_v].k);
  }
  return (res);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> G[i].k;
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    G[v1].to.push_back(v2);
    G[v2].to.push_back(v1);
  }
  cin >> s;
  G[s].b = true;
  cout << f();
exit:
  return (0);
}

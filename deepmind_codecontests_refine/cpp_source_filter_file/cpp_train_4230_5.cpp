#include <bits/stdc++.h>
using namespace std;
int pos = 0, n, k, val[100005], izq[100005], der[100005];
vector<pair<int, int> > q;
vector<int> g[100005];
long double resp[100005];
void dfs(int v, int menor, int mayor, long long sum, int ct) {
  if (g[v].size() == 0) {
    while (q[pos].first > menor && q[pos].first < mayor && pos < k) {
      resp[q[pos].second] = (1. * sum) / ct;
      pos++;
    }
  } else {
    int to1 = g[v][0], to2 = g[v][1];
    if (val[to1] > val[to2]) swap(to1, to2);
    dfs(to1, menor, val[v], sum + (long long)der[v], ct + 1);
    dfs(to1, val[v], mayor, sum + (long long)izq[v], ct + 1);
  }
}
int main() {
  scanf("%d", &n);
  int ini;
  vector<pair<int, int> > vaux;
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d %d", &p, &val[i]);
    vaux.push_back(make_pair(val[i], i));
    if (p != -1) {
      g[p - 1].push_back(i);
    } else
      ini = i;
  }
  sort(vaux.begin(), vaux.end());
  for (int i = 1; i + 1 < vaux.size(); i++) {
    izq[vaux[i].second] = vaux[i - 1].first;
    der[vaux[i].second] = vaux[i + 1].first;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    q.push_back(make_pair(x, i));
  }
  sort(q.begin(), q.end());
  dfs(ini, -1 << 30, 1 << 30, 0, 0);
  for (int i = 0; i < k; i++) {
    printf("%.10lf\n", (double)resp[i]);
  }
}

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000001542;
vector<pair<int, int> > edge[5005];
long long s[5005], c[5005], sv[5005], ss[5005], ans = INF;
int e[5005][3];
int n;
void dfs(int dep, int prev) {
  c[dep] = 1;
  s[dep] = 0;
  for (int i = 0; i < edge[dep].size(); i++)
    if (edge[dep][i].first != prev) {
      dfs(edge[dep][i].first, dep);
      c[dep] += c[edge[dep][i].first];
      s[dep] +=
          s[edge[dep][i].first] + edge[dep][i].second * c[edge[dep][i].first];
    }
}
void dfs2(int dep, int prev, long long sn, long long cn) {
  s[dep] += sn;
  sv[dep] = s[dep];
  ss[dep] = s[dep];
  for (int i = 0; i < edge[dep].size(); i++)
    if (edge[dep][i].first != prev) {
      dfs2(edge[dep][i].first, dep,
           s[dep] - s[edge[dep][i].first] -
               edge[dep][i].second * c[edge[dep][i].first] +
               edge[dep][i].second * (cn + c[dep] - c[edge[dep][i].first]),
           cn + c[dep] - c[edge[dep][i].first]);
      sv[dep] = min(sv[dep], sv[edge[dep][i].first]);
      ss[dep] += ss[edge[dep][i].first];
    }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    a--;
    b--;
    edge[a].push_back(make_pair(b, d));
    edge[b].push_back(make_pair(a, d));
    e[i][0] = a;
    e[i][1] = b;
    e[i][2] = d;
  }
  for (int i = 0; i < n - 1; i++) {
    int a = e[i][0], b = e[i][1], d = e[i][2];
    dfs(a, b);
    dfs(b, a);
    dfs2(a, b, 0, 0);
    dfs2(b, a, 0, 0);
    long long res =
        c[a] * sv[b] + c[b] * sv[a] + d * c[a] * c[b] + ss[a] / 2 + ss[b] / 2;
    ans = min(ans, res);
  }
  cout << ans;
  return 0;
}

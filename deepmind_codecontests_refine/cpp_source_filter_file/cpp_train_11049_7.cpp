#include <bits/stdc++.h>
using namespace std;
int n, r[100123], q[100123];
vector<pair<long long, long long> > g[100123];
pair<long long, long long> dfs(long long no, long long pai) {
  long long qnt = 0ll, resp = 0ll;
  int tam = g[no].size();
  for (int i = 0; i < tam; i++) {
    if (g[no][i].first == pai) continue;
    pair<long long, long long> ret = dfs(g[no][i].first, no);
    qnt += ret.first + 1ll;
    if (g[no][i].second)
      resp += ret.first + 1ll;
    else
      resp += ret.second;
  }
  r[no] = resp;
  q[no] = qnt;
  return pair<long long, long long>(qnt, resp);
}
void dfs2(int no, int pai) {
  int tam = g[no].size();
  for (int i = 0; i < tam; i++) {
    long long umno = g[no][i].first;
    if (umno == pai) continue;
    if (g[no][i].second)
      r[umno] += n - q[umno] - 1;
    else
      r[umno] = r[no];
    dfs2(umno, no);
  }
}
int main() {
  long long a, b, c, w;
  bool eh;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> c;
    eh = true;
    while (c) {
      w = c % 10;
      c /= 10;
      if (w == 4 || w == 7) continue;
      eh = false;
      break;
    }
    g[a].push_back(pair<long long, long long>(b, eh));
    g[b].push_back(pair<long long, long long>(a, eh));
  }
  dfs(1, -1);
  dfs2(1, -1);
  long long val = 0;
  for (int i = 1; i <= n; i++) val += (r[i] * (r[i] - 1));
  cout << val << endl;
}

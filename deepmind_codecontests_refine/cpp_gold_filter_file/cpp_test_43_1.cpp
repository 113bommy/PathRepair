#include <bits/stdc++.h>
using namespace std;
long long par3[200001];
pair<long long, long long> ma[200001];
long long ma3[200001];
vector<pair<long long, long long>> adj[200001];
long long find(long long no) {
  if (par3[no] == no) {
    return no;
  }
  par3[no] = find(par3[no]);
  return par3[no];
}
pair<long long, long long> par[200001][20];
long long lev[200001];
void dfs(long long no, long long par2 = -1, long long levv = 0) {
  if (par2 == -1) {
    par[no][0] = {-1, 0};
  }
  lev[no] = levv;
  for (auto j : adj[no]) {
    if (j.first != par2) {
      par[j.first][0] = {no, j.second};
      dfs(j.first, no, levv + 1);
    }
  }
}
long long lca(long long aa, long long bb) {
  if (aa == bb) {
    return 0;
  }
  long long ma = 0;
  if (lev[aa] > lev[bb]) {
    swap(aa, bb);
  }
  long long dif = lev[bb] - lev[aa];
  for (long long j = 19; j >= 0; j--) {
    if ((1 << j) & dif) {
      ma = max(ma, par[bb][j].second);
      bb = par[bb][j].first;
    }
  }
  if (aa == bb) {
    return ma;
  }
  for (long long j = 19; j >= 0; j--) {
    if (par[aa][j].first != par[bb][j].first) {
      ma = max(ma, par[bb][j].second);
      ma = max(ma, par[aa][j].second);
      aa = par[aa][j].first;
      bb = par[bb][j].first;
    }
  }
  ma = max(ma, par[aa][0].second);
  ma = max(ma, par[bb][0].second);
  return ma;
}
long long ans2[200001];
long long ans[200001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    par3[i] = i;
    cin >> ma[i].first;
    ma[i].second = i;
    ma3[i] = 0;
  }
  vector<pair<long long, pair<long long, long long>>> xx;
  for (long long i = 0; i < n - 1; i++) {
    long long aa, bb, cc, dd;
    cin >> aa >> bb >> cc >> dd;
    aa--;
    bb--;
    adj[aa].push_back({bb, dd});
    adj[bb].push_back({aa, dd});
    xx.push_back({cc, {aa, bb}});
  }
  dfs(0);
  for (long long j = 1; j < 20; j++) {
    for (long long i = 0; i < n; i++) {
      if (par[i][j - 1].first == -1) {
        par[i][j] = {-1, 0};
      } else {
        par[i][j].first = par[par[i][j - 1].first][j - 1].first;
        par[i][j].second =
            max(par[i][j - 1].second, par[par[i][j - 1].first][j - 1].second);
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    long long v, x;
    cin >> v >> x;
    x--;
    xx.push_back({v, {-(i + 1), x}});
  }
  sort(xx.begin(), xx.end());
  reverse(xx.begin(), xx.end());
  for (auto j : xx) {
    if (j.second.first < 0) {
      long long x = find(j.second.second);
      long long i = (-(j.second.first)) - 1;
      ans2[i] = ma[x].first;
      ans[i] = max(ma3[x], lca(j.second.second, ma[x].second));
    } else {
      long long x = find(j.second.first);
      long long y = find(j.second.second);
      if (ma[x].first > ma[y].first) {
        swap(x, y);
      }
      par3[x] = y;
      if (ma[x].first == ma[y].first) {
        ma3[y] = max(ma3[y], ma3[x]);
        ma3[y] = max(ma3[y], lca(ma[y].second, ma[x].second));
      }
    }
  }
  for (long long i = 0; i < q; i++) {
    cout << ans2[i] << " " << ans[i] << '\n';
  }
  return 0;
}

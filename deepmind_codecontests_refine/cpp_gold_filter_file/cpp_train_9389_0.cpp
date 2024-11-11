#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 10;
const int LGN = 20;
string s;
int n;
int r[LGN][MAXN];
int lcp(int a, int b) {
  int ans = 0;
  for (int i = LGN - 1; i >= 0; i--) {
    if (r[i][a] == r[i][b]) {
      ans += 1 << i;
      a += 1 << i;
      b += 1 << i;
    }
  }
  return ans;
}
int suf[MAXN];
void calSuf() {
  for (int i = 0; i < n; i++) r[0][i] = s[i];
  vector<pair<pair<int, int>, int> > v(n);
  for (int j = 1; j < LGN; j++) {
    for (int i = 0; i < n; i++)
      v[i] = make_pair(make_pair(r[j - 1][i], (i + (1 << (j - 1)) < n)
                                                  ? r[j - 1][i + (1 << (j - 1))]
                                                  : -1),
                       i);
    sort((v).begin(), (v).end());
    for (int i = 0; i < n; i++)
      r[j][v[i].second] =
          (i && v[i - 1].first == v[i].first) ? r[j][v[i - 1].second] : i + 1;
  }
  for (int i = 0; i < n; i++) suf[i] = v[i].second;
}
int par[MAXN];
int sz[MAXN];
int gPar(int u) {
  if (par[u] == u) return u;
  return par[u] = gPar(par[u]);
}
inline long long int cmb(long long int x) { return (x * (x + 1)) / 2; }
vector<pair<int, int> > eve[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  calSuf();
  long long int ans = 0;
  for (int i = 0; i < n - 1; i++)
    eve[lcp(suf[i], suf[i + 1])].push_back(make_pair(i, i + 1));
  long long int sum = 0;
  for (int i = n; i; i--) {
    sum++;
    sz[n - i] = 1;
    par[n - i] = n - i;
    for (int j = 0; j < eve[i].size(); j++) {
      int u = suf[eve[i][j].first];
      int v = suf[eve[i][j].second];
      u = gPar(u);
      v = gPar(v);
      sum -= cmb(sz[u]);
      sum -= cmb(sz[v]);
      par[u] = v;
      sz[v] += sz[u];
      sum += cmb(sz[v]);
    }
    ans += sum;
  }
  cout << ans << endl;
  return 0;
}

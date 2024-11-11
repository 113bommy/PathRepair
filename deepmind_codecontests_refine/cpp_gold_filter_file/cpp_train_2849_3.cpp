#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
string s[1000000];
vector<int> g[100000];
int ans, sul, maxx, numa, numb, c, raod, i, j, k, q, n;
string a, b;
int fix[100000];
map<pair<int, int>, int> mapp;
int main() {
  cin >> q;
  for (i = 1; i <= q; i++) {
    cin >> a >> b;
    if (m[a] == 0)
      numa = m[a] = ++c;
    else
      numa = m[a];
    if (m[b] == 0)
      numb = m[b] = ++c;
    else
      numb = m[b];
    g[numa].push_back(numb);
    g[numb].push_back(numa);
    s[numa] = a;
    s[numb] = b;
    mapp[make_pair(numa, numb)] = 1;
    mapp[make_pair(numb, numa)] = 1;
  }
  n = c;
  cout << n << endl;
  for (i = 1; i <= n; i++) {
    raod++;
    for (j = 0; j < g[i].size(); j++) fix[g[i][j]] = raod;
    maxx = 0;
    ans = 0;
    for (j = 1; j <= n; j++) {
      if (fix[j] == raod) continue;
      sul = 0;
      if (i == j) continue;
      for (k = 0; k < g[j].size(); k++)
        if (fix[g[j][k]] == raod) sul++;
      if (sul > maxx) {
        maxx = sul;
        ans = 1;
      } else if (sul == maxx)
        ans++;
    }
    cout << s[i] << " " << ans << endl;
  }
}

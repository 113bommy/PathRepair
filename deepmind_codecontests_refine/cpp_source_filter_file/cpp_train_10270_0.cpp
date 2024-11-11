#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[100000];
unordered_map<string, int> hs;
string ths[100000];
int shs[100000];
queue<int> o;
int path[1000000];
unordered_map<string, int> numb;
int vor[1000000];
vector<pair<string, int> > ansik;
inline string make_project_great_again(string t, string s, int ver) {
  string l = t + s;
  if (hs.count(t + s) == 0) {
    hs[l] = 0;
    hs[l] = hs.size() - 1;
    ths[hs.size() - 1] = t;
    shs[hs.size() - 1] = ver;
  }
  if (numb.count(t) == 0) {
    numb[t] = 0;
    numb[t] = numb.size() - 1;
  }
  return l;
}
string read_erundu() {
  string t;
  cin >> t;
  int ver, ver1;
  cin >> ver;
  ver1 = ver;
  string s;
  while (ver1 > 0) {
    s += char('0' + ver1 % 10);
    ver1 /= 10;
  }
  return make_project_great_again(t, s, ver);
}
int main() {
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < 2000; i++) {
    path[i] = -1;
    vor[i] = -1;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string t = read_erundu();
    int m;
    cin >> m;
    for (int j = 1; j <= m; j++) {
      string s = read_erundu();
      g[hs[t]].push_back(hs[s]);
    }
  }
  int ans = -1;
  o.push(0);
  path[0] = 0;
  vor[0] = shs[0];
  while (!o.empty()) {
    int v = o.front();
    o.pop();
    int vprj = numb[ths[v]];
    int vver = shs[v];
    if (vor[v] > vver) {
      continue;
    } else {
      if (ans >= 0) ansik.push_back({ths[v], shs[v]});
      ans++;
    }
    for (int i = 0; i < g[v].size(); i++) {
      int to = g[v][i];
      int prj = numb[ths[to]];
      int ver = shs[to];
      if (path[prj] == -1 || path[prj] == path[vprj] + 1 && vor[prj] < ver) {
        path[prj] = path[vprj] + 1;
        vor[prj] = ver;
        o.push(to);
      }
    }
  }
  cout << ans << endl;
  sort(ansik.begin(), ansik.end());
  for (int i = 0; i < ansik.size(); i++) {
    cout << ansik[i].first << " " << ansik[i].second << endl;
  }
  return 0;
}

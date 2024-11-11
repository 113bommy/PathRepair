#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vii = vector<ii>;
vector<int> g[6666];
int lerank[6666];
int vals[6666];
int main() {
  (memset(vals, -1, sizeof(vals)));
  string s;
  getline(cin, s);
  int x = s.find_first_of(')');
  string gg = s.substr(2, x - 2);
  string ff = s.substr(x + 3);
  ff = ff.substr(0, ff.size() - 1);
  map<string, vector<int>> remap;
  map<string, int> nodemap;
  int ggi = 0;
  int cnt = 0;
  int ncnt = 0;
  while (1) {
    int gge = gg.find_first_not_of('_', ggi);
    string ss = gg.substr(ggi, gge - ggi);
    remap[ss].push_back(cnt++);
    if (nodemap.find(ss) == nodemap.end()) nodemap[ss] = ncnt++;
    ggi = gge + 1;
    if (gge == -1) break;
  }
  vector<string> podm;
  int ffi = 0;
  while (1) {
    int ffe = ff.find_first_of(',', ffi);
    string ss = ff.substr(ffi, ffe - ffi);
    int op = ss.find_first_not_of('_');
    string a = ss.substr(0, op);
    string b = ss.substr(op + 1);
    if (a == b) {
      cout << "false" << endl;
      return 0;
    }
    if (ss[op] == '>') {
      g[nodemap[b]].push_back(nodemap[a]);
      lerank[nodemap[a]]++;
    } else {
      g[nodemap[a]].push_back(nodemap[b]);
      lerank[nodemap[b]]++;
    }
    ffi = ffe + 1;
    if (ffe == -1) break;
  }
  vector<int> q;
  for (int i = 0; i < ncnt; i++)
    if (lerank[i] == 0) q.push_back(i);
  int val = 0;
  int vis = 0;
  while (q.size()) {
    vector<int> next;
    for (int node : q) {
      vis++;
      vals[node] = val;
      for (int neigh : g[node]) {
        lerank[neigh]--;
        if (lerank[neigh] == 0) next.push_back(neigh);
      }
    }
    val++;
    q = move(next);
  }
  if (vis != ncnt || val >= 11) {
    cout << "false" << endl;
    return 0;
  }
  string res(cnt, '0');
  for (auto& p : nodemap) {
    for (int mm : remap[p.first]) {
      res[mm] = vals[p.second] + '0';
    }
  }
  cout << res << endl;
  return 0;
}

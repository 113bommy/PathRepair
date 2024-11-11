#include <bits/stdc++.h>
using namespace std;
vector<char> v[200];
string topo;
int bs[200];
bool imposs = false;
void dfs(char c) {
  if (imposs) return;
  bs[c] = 1;
  for (int i = 0; i < v[c].size(); i++) {
    if (bs[v[c][i]] != 2) {
      if (bs[v[c][i]] == 1) {
        imposs = true;
        return;
      }
      dfs(v[c][i]);
    }
  }
  topo.push_back(c);
  bs[c] = 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> vs;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  for (int i = 0; i < n - 1; i++) {
    bool masuk = false;
    for (int j = 0; j < min(vs[i].size(), vs[i + 1].size()); j++) {
      if (vs[i][j] != vs[i + 1][j]) {
        v[vs[i][j]].push_back(vs[i + 1][j]);
        masuk = true;
        break;
      }
    }
    if (!masuk) {
      if (vs[i].size() > vs[i + 1].size()) {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  memset(bs, 0, sizeof bs);
  for (char c = 'z'; c >= 'a'; c--) {
    if (!bs[c]) {
      dfs(c);
    }
  }
  if (imposs) {
    cout << "Impossible\n";
  } else {
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < topo.size(); i++) {
      cout << topo[i];
    }
    cout << endl;
  }
  return 0;
}

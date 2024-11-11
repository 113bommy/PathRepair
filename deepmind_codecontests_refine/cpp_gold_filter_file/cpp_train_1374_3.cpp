#include <bits/stdc++.h>
using namespace std;
class SCC {
 private:
  vector<vector<int>> vin, vout;
  vector<int> f, f1, mno;
  void dfsvout(int v, int fa) {
    f[v] = fa;
    for (int i = 0; i < vout[v].size(); i++)
      if (f[vout[v][i]] == -1) dfsvout(vout[v][i], fa);
    mno.push_back(v);
  }
  void dfsvin(int v, int fa) {
    if (f1[v] != -1) return;
    f1[v] = fa;
    for (int i = 0; i < vin[v].size(); i++) dfsvin(vin[v][i], fa);
  }
  int ko = 0;

 public:
  SCC(int n, vector<pair<int, int>> l) {
    vin.resize(n);
    vout.resize(n);
    f.resize(n, -1);
    for (pair<int, int> i : l) {
      vin[i.second].push_back(i.first);
      vout[i.first].push_back(i.second);
    }
    for (int i = 0; i < n; i++)
      if (f[i] == -1) dfsvout(i, 1);
    f1.resize(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      if (f1[mno[i]] == -1) {
        dfsvin(mno[i], ko);
        ko++;
      }
    }
  }
  int size() { return ko; }
  int operator[](const int &i) const { return f1[i]; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> l;
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b) continue;
      l.push_back(make_pair(a - 1, b - 1));
    }
    SCC s(n, l);
    if (s.size() == 1) {
      cout << "No\n";
      continue;
    }
    vector<bool> dobre(s.size(), 1);
    for (pair<int, int> i : l) {
      if (s[i.first] == s[i.second]) continue;
      dobre[s[i.second]] = 0;
    }
    cout << "Yes\n";
    vector<bool> ans(n, 0);
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (dobre[i] == 0) continue;
      int cnt = 0;
      for (int j = 0; j < n; j++)
        if (s[j] == i) cnt++;
      cout << n - cnt << " " << cnt << endl;
      for (int j = 0; j < n; j++)
        if (s[j] != i) cout << j + 1 << " ";
      cout << endl;
      for (int j = 0; j < n; j++)
        if (s[j] == i) cout << j + 1 << " ";
      cout << endl;
      break;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
map<long long, vector<vector<long long> > > me;
int pro = 1, mo = 12345;
int it[30];
vector<vector<long long> > tmp;
vector<vector<long long> > rec(long long a) {
  if (me[a].size()) return me[a];
  int i, j, k;
  vector<vector<long long> > ret = tmp, mae = rec(a / 2), ato = rec(a - a / 2);
  for (i = 0; i < pro; i++)
    for (j = 0; j < pro; j++)
      for (k = 0; k < pro; k++) {
        ret[i][j] = (ret[i][j] + mae[i][k] * ato[k][j]) % mo;
      }
  return me[a] = ret;
}
int cal(int a, int b, int c) {
  if ((a / b) % c < c - 1)
    return a + b;
  else
    return a - b * (c - 1);
}
int main() {
  int i, j, k, m, a;
  string s;
  long long out = 0, n;
  memset(it, 0, sizeof(it));
  vector<vector<pair<int, int> > > it2;
  vector<vector<long long> > one, ret;
  vector<long long> cl;
  vector<pair<int, int> > cl2;
  for (i = 0; i < 30; i++) it2.push_back(cl2);
  for (i = 0; i < 125; i++) cl.push_back(0);
  for (j = 0; j < 125; j++) tmp.push_back(cl);
  one = tmp;
  cin >> n >> m;
  if (n == 0) {
    cout << "0" << endl;
    return 0;
  }
  if (m == 0) {
    cout << "0" << endl;
    return 0;
  }
  for (i = 0; i < m; i++) {
    cin >> s >> a;
    it[(s[0] - 'A')] += pro;
    it2[(s[0] - 'A')].push_back(make_pair(pro, a));
    pro *= a;
  }
  for (i = 0; i < 26; i++) {
    if (it2[i].size() < 1) continue;
    for (j = 0; j < pro; j++) {
      int x = j;
      for (k = 0; k < it2[i].size(); k++) {
        pair<int, int> t = it2[i][k];
        x = cal(x, t.first, t.second);
      }
      one[j][x] = 1;
    }
  }
  for (i = 0; i < pro; i++) {
    for (j = 0; j < pro; j++) {
    }
  }
  me[1] = one;
  ret = rec(n);
  for (i = 0; i < pro; i++) {
    int f = 0;
    for (j = 0; j < 26; j++) {
      if (it2[j].size() < 1) continue;
      int f2 = 0;
      for (k = 0; k < it2[j].size(); k++) {
        pair<int, int> t = it2[j][k];
        if ((i / t.first) % t.second == 0) f2 = 1;
      }
      if (f2 < 1) f = 1;
    }
    if (f < 1) out = (out + ret[0][i]) % mo;
  }
  cout << out << endl;
  return 0;
}

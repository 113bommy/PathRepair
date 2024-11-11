#include <bits/stdc++.h>
using namespace std;
int d[500][500];
int INF = 1000000000;
int main() {
  string s, t;
  cin >> s >> t;
  int n;
  cin >> n;
  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = i + 1; j <= 'z'; j++) d[i][j] = d[j][i] = INF;
    d[i][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    string a, b;
    int v;
    cin >> a >> b >> v;
    d[a[0]][b[0]] = min(d[a[0]][b[0]], v);
  }
  for (int k = 'a'; k <= 'z'; k++)
    for (int i = 'a'; i <= 'z'; i++)
      for (int j = 'a'; j <= 'z'; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  string res = s;
  int cost = 0;
  if (s.size() != t.size())
    cout << "-1" << endl;
  else {
    bool ok = true;
    for (int i = 0; ok && i < s.size(); i++) {
      int c = INF;
      int ch = 0;
      for (int j = 'a'; j <= 'z'; j++) {
        if (c > d[t[i]][j] + d[s[i]][j]) {
          c = d[t[i]][j] + d[s[i]][j];
          ch = j;
        }
      }
      if (c >= INF)
        ok = false;
      else {
        cost += c;
        res[i] = ch;
      }
    }
    if (!ok)
      cout << "-1" << endl;
    else {
      cout << cost << endl;
      cout << res << endl;
    }
  }
  return 0;
}

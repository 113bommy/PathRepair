#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  vector<string> v;
  pair<int, int> mx = make_pair(0, 0), mn = make_pair(-1, -1);
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    for (int j = 0; j < m; j++)
      if (s[j] == '*') {
        if (i > mx.first) mx.first = i;
        if (j > mx.second) mx.second = j;
        if (i < mn.first || mn.first == -1) mn.first = i;
        if (j < mn.second || mn.second == -1) mn.second = i;
      }
    v.push_back(s);
  }
  if (v[mx.first][mx.second] == '.')
    cout << ++mx.first << ' ' << ++mx.second << endl;
  else if (v[mx.first][mn.second] == '.')
    cout << ++mx.first << ' ' << ++mn.second << endl;
  else if (v[mn.first][mn.second] == '.')
    cout << ++mn.first << ' ' << ++mn.second << endl;
  else if (v[mn.first][mx.second] == '.')
    cout << ++mn.first << ' ' << ++mx.second << endl;
}

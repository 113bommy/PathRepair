#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int d[maxn][maxn];
int check[maxn][maxn];
pair<int, int> p[maxn][maxn];
string inp;
bool dfs(pair<int, int> v) {
  bool ok = true;
  if (0) {
    cerr << "````````````````````````````````````" << endl;
    cerr << "Called by" << p[v.first][v.second].first << " "
         << p[v.first][v.second].second << endl;
    cerr << "Calling : " << v.first << " " << v.second << endl;
  }
  check[v.first][v.second] = 1;
  for (int i = -1; i <= 1; i++)
    for (int j = -1; j <= 1; j++) {
      if ((i != 0 && j != 0) || (i == j)) continue;
      pair<int, int> temp = make_pair(v.first + i, v.second + j);
      if (!d[temp.first][temp.second]) continue;
      if (check[temp.first][temp.second] == 1 && p[v.first][v.second] != temp) {
        if (0) {
          cerr << "GOt false in " << temp.first << " " << temp.second << endl;
          cerr << i << " " << j << endl;
        }
        ok = false;
      } else if (check[temp.first][temp.second] == 0) {
        p[temp.first][temp.second] = v;
        ok = dfs(temp);
      }
    }
  check[v.first][v.second] = 2;
  return ok;
}
int main() {
  cin >> inp;
  pair<int, int> cur = make_pair(150, 150);
  d[cur.first][cur.second] = 1;
  bool ok = true;
  for (int i = 0; i < inp.size(); i++) {
    if (inp[i] == 'L')
      cur.second--;
    else if (inp[i] == 'R')
      cur.second++;
    else if (inp[i] == 'U')
      cur.first--;
    else
      cur.first++;
    d[cur.first][cur.second]++;
    if (d[cur.first][cur.second] > 1) ok = false;
  }
  if (ok) ok = dfs(cur);
  if (ok)
    cout << "OK" << endl;
  else
    cout << "BUG" << endl;
  return 0;
}

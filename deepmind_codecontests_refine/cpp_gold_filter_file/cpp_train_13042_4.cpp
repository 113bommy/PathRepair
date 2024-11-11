#include <bits/stdc++.h>
using namespace std;
ifstream fin("Sisend.txt");
long long t, n, m, arv;
string s[105];
vector<int> v;
void pane(int i1, int j1, int i2, int j2, int i3, int j3) {
  v.emplace_back(i1 + 1), v.emplace_back(j1 + 1), v.emplace_back(i2 + 1),
      v.emplace_back(j2 + 1), v.emplace_back(i3 + 1), v.emplace_back(j3 + 1);
  if (s[i1][j1] == '0')
    s[i1][j1] = '1';
  else
    s[i1][j1] = '0';
  if (s[i2][j2] == '0')
    s[i2][j2] = '1';
  else
    s[i2][j2] = '0';
  if (s[i3][j3] == '0')
    s[i3][j3] = '1';
  else
    s[i3][j3] = '0';
  arv++;
}
vector<int> x = {1, 0, -1, 0, 1, 0, -1, 0}, y = {0, 1, 0, -1, 0, 1, 0, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> t;
  while (t--) {
    v.resize(0);
    arv = 0;
    cin >> n >> m;
    for (int(i) = (0); ((i)) < ((n)); ((i))++) cin >> s[i];
    for (int(i) = (0); ((i)) < ((n - 2)); ((i))++)
      for (int(j) = (0); ((j)) < ((m)); ((j))++)
        if (j % 2 or j == m - 1)
          if (s[i][j] == '1' and s[i][j - 1] == '1')
            pane(i, j - 1, i, j, i + 1, j);
          else if (s[i][j] == '1')
            pane(i, j, i + 1, j - 1, i + 1, j);
          else if (s[i][j - 1] == '1')
            pane(i, j - 1, i + 1, j - 1, i + 1, j);
    int i = n - 2;
    for (int(j) = (0); ((j)) < ((m - 1)); ((j))++)
      if (s[i][j] == '1' and s[i + 1][j] == '1')
        pane(i, j, i, j + 1, i + 1, j);
      else if (s[i][j] == '1')
        pane(i, j, i, j + 1, i + 1, j + 1);
      else if (s[i + 1][j] == '1')
        pane(i + 1, j, i, j + 1, i + 1, j + 1);
    int j = m - 1;
    if (s[i][j] == '1' and s[i + 1][j] == '1') {
      pane(i, j, i, j - 1, i + 1, j - 1);
      pane(i + 1, j, i, j - 1, i + 1, j - 1);
    } else if (s[i][j] == '1') {
      pane(i, j, i, j - 1, i + 1, j - 1);
      pane(i, j, i, j - 1, i + 1, j);
      pane(i + 1, j - 1, i, j, i + 1, j);
    } else if (s[i + 1][j] == '1') {
      pane(i + 1, j, i, j - 1, i + 1, j - 1);
      pane(i, j, i, j - 1, i + 1, j);
      pane(i + 1, j - 1, i, j, i + 1, j);
    }
    cout << arv << endl;
    for (int(i) = (0); ((i)) < ((v.size())); ((i))++) {
      cout << v[i] << " ";
      if ((i + 1) % 6 == 0) cout << endl;
    }
  }
}

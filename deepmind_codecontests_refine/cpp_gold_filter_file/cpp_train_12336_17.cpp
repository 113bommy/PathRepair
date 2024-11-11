#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;
  int n = ((int)s.size());
  int m = ((int)t.size());
  vector<vector<int> > a(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; ++i) a[i][0] = i;
  for (int j = 0; j <= m; ++j) a[0][j] = j;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1])
        a[i][j] = a[i - 1][j - 1];
      else
        a[i][j] = min(a[i - 1][j], min(a[i][j - 1], a[i - 1][j - 1])) + 1;
    }
  cout << a[n][m] << endl;
  int i = n, j = m;
  vector<string> res;
  vector<int> b;
  vector<char> ch;
  while (true) {
    if ((i == 0) && (j == 0)) break;
    if ((i != 0) && (j != 0))
      if (s[i - 1] == t[j - 1]) {
        --i;
        --j;
        continue;
      }
    if ((i > 0) && (a[i][j] == a[i - 1][j] + 1)) {
      res.push_back("DELETE");
      b.push_back(j + 1);
      ch.push_back('a');
      --i;
      continue;
    }
    if ((j > 0) && (a[i][j] == a[i][j - 1] + 1)) {
      res.push_back("INSERT");
      b.push_back(j);
      ch.push_back(t[j - 1]);
      --j;
      continue;
    }
    if ((i > 0) && (j > 0) && (a[i][j] == a[i - 1][j - 1] + 1)) {
      res.push_back("REPLACE");
      b.push_back(j);
      ch.push_back(t[j - 1]);
      --i;
      --j;
      continue;
    }
  }
  reverse((res).begin(), (res).end());
  reverse((b).begin(), (b).end());
  reverse((ch).begin(), (ch).end());
  for (int i = 0; i < ((int)res.size()); ++i) {
    cout << res[i] << " " << b[i];
    if (res[i] != "DELETE") cout << " " << ch[i];
    cout << endl;
  }
  return 0;
}

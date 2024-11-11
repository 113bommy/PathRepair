#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
vector<int> v[30007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m, p = 0;
    cin >> n >> m;
    string s[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      s[i] = " " + s[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == '0') continue;
        int x = i + 1, y = j + 1;
        if (j == m) y = j - 1;
        if (i == n) x = i - 1;
        if (s[i][y] == '1' && s[x][j] == '1' && s[x][y] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(y);
          v[p].push_back(i);
          v[p].push_back(y);
          p++;
          v[p].push_back(x);
          v[p].push_back(y);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
        } else if (s[i][y] == '1' && s[x][j] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
        } else if (s[i][y] == '1' && s[x][y] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
        } else if (s[x][j] == '1' && s[x][y] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
        } else if (s[i][y] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
        } else if (s[x][j] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
          v[p].push_back(x);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
        } else if (s[x][y] == '1') {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
          v[p].push_back(x);
          v[p].push_back(y);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
        } else {
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(j);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(j);
          p++;
          v[p].push_back(i);
          v[p].push_back(j);
          v[p].push_back(i);
          v[p].push_back(y);
          v[p].push_back(x);
          v[p].push_back(y);
          p++;
        }
        s[i][j] = '0';
        s[i][y] = '0';
        s[x][j] = '0';
        s[x][y] = '0';
      }
    }
    cout << p << endl;
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < 6; j++) cout << v[i][j] << " ";
      cout << endl;
    }
    for (int i = 0; i < p; i++) v[i].clear();
  }
}

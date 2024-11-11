#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > adj[2010 * 2];
int color[2010 * 2];
bool impossible;
void dfs(int u, int co) {
  if (color[u] == co) return;
  if (color[u] != -1) {
    impossible = true;
    return;
  }
  color[u] = co;
  for (auto V : adj[u]) {
    int v = V.first;
    int typ = V.second;
    if (typ == 0)
      dfs(v, co);
    else
      dfs(v, 1 - co);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  int a[n + 10][n + 10];
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) a[i][j] = s[j - 1] - '0';
  }
  int b[n + 10][n + 10];
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) b[i][j] = s[j - 1] - '0';
  }
  int mag[n + 10];
  string mmm;
  cin >> mmm;
  for (int i = 1; i <= n; i++) mag[i] = mmm[i - 1] - '0';
  for (int i = 1; i <= 2 * n; i++) adj[i].clear();
  memset(color, -1, sizeof(color));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int vala = a[i][j];
      int valb = b[i][j];
      int valr = mag[j];
      int valc = mag[i];
      if (valr + valc == 0) {
        if (vala == valb) continue;
        cout << -1;
        return 0;
      }
      if (valr + valc == 2) {
        if (vala == valb) {
          adj[i].push_back({j + n, 0});
          adj[j + n].push_back({i, 0});
        } else {
          adj[i].push_back({j + n, 1});
          adj[j + n].push_back({i, 1});
        }
        continue;
      }
      if (valr == 1) {
        if (vala == valb) {
          if (color[i] == 1) {
            cout << -1;
            return 0;
          }
          color[i] = 0;
        } else {
          if (color[i] == 0) {
            cout << -1;
            return 0;
          }
          color[i] = 1;
        }
      } else {
        if (vala == valb) {
          if (color[j + n] == 1) {
            cout << -1;
            return 0;
          }
          color[j + n] = 0;
        } else {
          if (color[j + n] == 0) {
            cout << -1;
            return 0;
          }
          color[j + n] = 1;
        }
      }
    }
  impossible = false;
  for (int i = 1; i <= 2 * n; i++)
    if (color[i] == -1) dfs(i, 0);
  if (impossible) {
    cout << -1;
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= 2 * n; i++)
    if (color[i] == 1) cnt++;
  cout << cnt << endl;
  for (int i = 1; i <= n; i++)
    if (color[i] == 1) cout << "row " << i - 1 << endl;
  for (int i = n + 1; i <= 2 * n; i++)
    if (color[i] == 1) cout << "col " << i - n - 1 << endl;
  return 0;
}

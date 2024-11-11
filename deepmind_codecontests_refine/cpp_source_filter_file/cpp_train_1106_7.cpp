#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[26], t[26], hm[2510];
string str[2510];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  for (auto x : str[0]) cnt[x - 97]++;
  int dis = (*max_element(cnt, cnt + 26) < 2);
  for (int i = 0; i < n; i++) {
    memset(t, 0, sizeof(t));
    for (auto x : str[i]) t[x - 97]++;
    for (int i = 0; i < 26; i++)
      if (t[i] != cnt[i]) {
        cout << -1 << endl;
        return 0;
      }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (str[0][j] != str[i][j]) hm[i]++;
  }
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      int ok = 1;
      for (int k = 1; k < n; k++) {
        int dx = 0;
        if (str[0][i] != str[k][i])
          dx--;
        else
          dx++;
        if (str[0][j] != str[k][j])
          dx--;
        else
          dx++;
        if (str[0][i] == str[k][j])
          ;
        else
          dx++;
        if (str[0][j] == str[k][i])
          ;
        else
          dx++;
        if (hm[k] + dx > 2) {
          ok = 0;
          break;
        }
        if (dis && hm[k] + dx == 0) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        swap(str[0][i], str[0][j]);
        cout << str[0] << endl;
        return 0;
      }
    }
  cout << -1 << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool f[110][110][2][60];
int main() {
  string str;
  cin >> str;
  int n = str.size();
  int m;
  cin >> m;
  memset(f, 0, sizeof(f));
  f[0][0][1][0] = 1;
  for (int i = 0; i < n; i++) {
    char ch = str[i];
    for (int dist = 0; dist <= n; dist++)
      for (int dir = 0; dir <= 1; dir++)
        for (int opr = 0; opr <= m; opr++)
          if (f[i][dist][dir][opr])
            if (ch == 'F') {
              int delta = dir ? 1 : -1;
              if (dist == 0)
                f[i + 1][1][1][opr] = 1;
              else
                f[i + 1][dist + delta][dir][opr] = 1;
              f[i + 1][dist][1 - dir][opr + 1] = 1;
            } else {
              f[i + 1][dist][1 - dir][opr] = 1;
              int delta = dir ? 1 : -1;
              if (dist == 0)
                f[i + 1][1][1][opr + 1] = 1;
              else
                f[i + 1][dist + delta][1 - dir][opr + 1] = 1;
            }
  }
  int ans = 0;
  for (int dist = 0; dist <= n; dist++)
    for (int dir = 0; dir <= 1; dir++)
      for (int opr = m; opr >= 0; opr -= 2)
        if (f[n][dist][dir][opr]) ans = ((ans) > (dist) ? (ans) : (dist));
  cout << ans << endl;
}

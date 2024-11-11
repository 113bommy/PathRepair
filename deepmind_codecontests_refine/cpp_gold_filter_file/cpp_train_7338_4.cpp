#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, m, comps = 0, dots = 0;
string z;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  cin >> z;
  bool indots = false;
  for (int i = 0; i < n; i++) {
    if (z[i] == '.')
      dots++, indots = true;
    else if (indots)
      comps++, indots = false;
  }
  if (indots) comps++, indots = false;
  int idx;
  char c;
  while (m--) {
    cin >> idx >> c;
    idx--;
    if (z[idx] == '.' && c != '.') {
      dots--;
      if (idx == 0 && n > 1 && z[idx + 1] != '.') comps--;
      if (idx == n - 1 && n > 1 && z[idx - 1] != '.') comps--;
      if (idx < n - 1 && idx > 0 && z[idx + 1] != '.' && z[idx - 1] != '.')
        comps--;
      if (idx < n - 1 && idx > 0 && z[idx + 1] == '.' && z[idx - 1] == '.')
        comps++;
    } else if (z[idx] != '.' && c == '.') {
      dots++;
      if (idx == 0 && n > 1 && z[idx + 1] != '.') comps++;
      if (idx == n - 1 && n > 1 && z[idx - 1] != '.') comps++;
      if (idx < n - 1 && idx > 0 && z[idx + 1] != '.' && z[idx - 1] != '.')
        comps++;
      if (idx < n && idx > 0 && z[idx + 1] == '.' && z[idx - 1] == '.') comps--;
    }
    z[idx] = c;
    cout << max(0, dots - comps) << '\n';
  }
}

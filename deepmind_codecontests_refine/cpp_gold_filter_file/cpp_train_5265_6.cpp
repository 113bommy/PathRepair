#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n';
  err(++it, args...);
}
const int NMAX = 1005;
int n, b[NMAX], imp[15][NMAX], par[15][NMAX];
int main() {
  int i, j, l, sgb;
  cin.sync_with_stdio(false);
  cin >> n;
  for (i = 0; (1 << i) < n; i++) {
    b[0] = 0;
    for (j = 1; j <= n; j += 2 * (1 << i))
      for (l = j; l <= (j + (1 << i) - 1) && l <= n; l++) b[++b[0]] = l;
    if (b[0]) {
      cout << b[0] << "\n";
      for (j = 1; j <= b[0]; j++) cout << b[j] << " ";
      cout << "\n";
      fflush(stdout);
      for (j = 1; j <= n; j++) cin >> imp[i][j];
    }
    b[0] = 0;
    for (j = (1 << i) + 1; j <= n; j += 2 * (1 << i))
      for (l = j; l <= (j + (1 << i) - 1) && l <= n; l++) b[++b[0]] = l;
    if (b[0]) {
      cout << b[0] << "\n";
      for (j = 1; j <= b[0]; j++) cout << b[j] << " ";
      cout << "\n";
      fflush(stdout);
      for (j = 1; j <= n; j++) cin >> par[i][j];
    }
    sgb = i;
  }
  cout << "-1\n";
  fflush(stdout);
  for (i = 1; i <= n; i++) {
    int ans = 1 << 30;
    for (j = 0; j <= sgb; j++) {
      int aux = (i - 1) % (2 * (1 << j));
      if (aux < (1 << j))
        ans = min(ans, par[j][i]);
      else
        ans = min(ans, imp[j][i]);
    }
    cout << ans << " ";
  }
  fflush(stdout);
  return 0;
}

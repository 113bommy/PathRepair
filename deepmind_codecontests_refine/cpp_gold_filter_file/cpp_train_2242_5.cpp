#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int vis[100004], d[100005];
string s;
int main() {
  ios::sync_with_stdio(false);
  int n, flag = 0;
  cin >> n;
  cin >> s;
  for (int i = (0); i <= (n - 1); i++) cin >> d[i];
  int i = 0;
  while (i < n && i >= 0) {
    if (vis[i]) {
      flag = 1;
      break;
    }
    vis[i] = 1;
    if (s[i] == '>')
      i += d[i];
    else
      i -= d[i];
  }
  if (flag)
    cout << "INFINITE\n";
  else
    cout << "FINITE\n";
  return 0;
}

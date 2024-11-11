#include <bits/stdc++.h>
using namespace std;
int f[301][301];
int n;
string name[500001];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> name[i];
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    int dl = (int)name[i].length();
    char l = name[i][0], r = name[i][dl - 1];
    for (char first = 'a'; first <= 'z'; ++first)
      if (f[first][r] != 0) f[first][r] = max(f[first][r], f[first][l] + dl);
    f[l][r] = max(f[l][r], dl);
  }
  int ans = 0;
  for (int i = 0; i <= 300; ++i) ans = max(ans, f[i][i]);
  cout << ans;
  return 0;
}

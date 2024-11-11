#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 1e9 + 7;
string res, a[110], ans;
char lt;
bool isU[110], vis[110];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < a[i].length(); j++)
      if (isupper(a[i][j])) a[i][j] -= 'A' - 'a';
  }
  cin >> res;
  ans = res;
  for (int i = 0; i < res.length(); i++)
    if (isupper(res[i])) {
      res[i] -= 'A' - 'a';
      isU[i] = 1;
    }
  cin >> lt;
  for (int i = 0; i < res.length(); i++)
    for (int j = 0; j < n; j++)
      if (res[i] == a[j][0]) {
        int k;
        for (k = 0; k < a[j].length(); k++)
          if (res[i + k] != a[j][k]) break;
        if (k == a[j].length())
          for (k = 0; k < a[j].length(); k++) {
            if (vis[i + k]) continue;
            if (res[i + k] != lt)
              ans[i + k] = isU[i + k] ? lt - 'a' + 'A' : lt;
            else
              for (int L = 'a'; L <= 'z'; L++)
                if (res[i + k] != L) {
                  ans[i + k] = isU[i + k] ? L - 'a' + 'A' : L;
                  break;
                }
            vis[i + k] = 1;
          }
      }
  cout << ans << endl;
  return 0;
}

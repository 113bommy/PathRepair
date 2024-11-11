#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e3 + 10;
const int block = 400;
bool f[N][N];
int ff[N][N];
int n, q;
string s;
int main() {
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; ++i) {
    for (int len = 0; i - len >= 0 && i + len < n; ++len)
      if (s[i + len] == s[i - len])
        f[i - len][i + len] = true;
      else
        break;
    for (int len = 0; i - len >= 0 && i + len + 1 < n; ++len)
      if (s[i - len] == s[i + len + 1])
        f[i - len][i + len + 1] = true;
      else
        break;
  }
  for (int i = 0; i < n; ++i) ff[i][i] = 1;
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len - 1 < n; ++i) {
      ff[i][i + len - 1] = ff[i + 1][i + len - 1] + ff[i][i + len - 2] -
                           ff[i + 1][i + len - 2] + f[i][i + len - 1];
    }
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    printf("%d\n", ff[l][r]);
  }
  return 0;
}

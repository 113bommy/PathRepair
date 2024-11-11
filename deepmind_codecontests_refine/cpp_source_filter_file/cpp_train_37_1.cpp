#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(const T& c) {
  return c.size();
}
using namespace std;
const int maxn = 1000000 + 10;
int a[maxn], s[maxn];
int n, r, c;
int l;
string st[maxn];
int nt[maxn];
int res;
int bk[maxn][20];
int bd, kt;
int main() {
  cin >> n >> r >> c;
  for (int i = (1), _b = (n); i <= _b; i++) {
    cin >> st[i];
    a[i] = st[i].length();
    s[i] = s[i - 1] + a[i];
  }
  l = 1;
  for (int i = (1), _b = (n); i <= _b; i++) {
    while (l <= i && s[i] - s[l - 1] + i - l > c) l++;
    bk[i][0] = l - 1;
    if (bk[i][0] == i) bk[i][0] = -1;
  }
  for (int j = (1), _b = (n); j <= _b; j++)
    for (int i = (1), _b = (n); i <= _b; i++) {
      if (bk[i][j - 1] != -1)
        bk[i][j] = bk[bk[i][j - 1]][j - 1];
      else
        bk[i][j] = -1;
    }
  for (int i = (1), _b = (n); i <= _b; i++) {
    int sr = r;
    int p = i;
    for (int j = (20), _a = (0); j >= _a; j--) {
      if ((sr >= (1 << j)) && (bk[p][j] != -1)) {
        sr -= 1 << j;
        p = bk[p][j];
      }
    }
    if (res < i - p) {
      res = i - p;
      bd = p + 1;
      kt = i;
    }
  }
  int sum = 1000000000;
  for (int i = (bd), _b = (kt); i <= _b; i++) {
    sum = sum + 1 + a[i];
    if (sum > c) {
      if (sum < 1000000000) cout << endl;
      cout << st[i];
      sum = a[i];
    } else
      cout << ' ' << st[i];
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}

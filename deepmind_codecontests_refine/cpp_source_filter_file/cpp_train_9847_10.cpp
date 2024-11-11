#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch;
  bool flag = false;
  while (ch = getchar(), ch < '!')
    ;
  if (ch == '-') ch = getchar(), flag = true;
  while (x = 10 * x + ch - '0', ch = getchar(), ch > '!')
    ;
  if (flag) x = -x;
}
inline int cat_max(const int &a, const int &b) { return a > b ? a : b; }
inline int cat_min(const int &a, const int &b) { return a < b ? a : b; }
const int maxn = 5010;
const int maxm = 1024;
map<string, int> mp;
char vari[maxn][maxm], va[maxn][maxm];
int typ[maxn], a[maxn], b[maxn], ans1[maxm], ans2[maxm];
char tmp[maxm], tt[maxm];
int n, m, val[maxm];
int check(int x, int t) {
  val[0] = t;
  for (int i = 1; i <= n; ++i) {
    if (typ[i] == -1)
      val[i] = va[i][x] - '0';
    else if (typ[i] == 1)
      val[i] = val[a[i]] ^ val[b[i]];
    else if (typ[i] == 2)
      val[i] = val[a[i]] | val[b[i]];
    else
      val[i] = val[a[i]] & val[b[i]];
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) sum += val[i];
  return sum;
}
int main() {
  read(n);
  read(m);
  mp["?"] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", vari[i]);
    mp[vari[i]] = i;
    scanf("%s%s", tt, va[i] + 1);
    if (va[i][1] == '0' || va[i][1] == '1')
      typ[i] = -1;
    else {
      a[i] = mp[va[i] + 1];
      scanf("%s", tmp);
      if (tmp[0] == 'X')
        typ[i] = 1;
      else if (tmp[0] == 'O')
        typ[i] = 2;
      else
        typ[i] = 3;
      scanf("%s", va[i] + 1);
      b[i] = mp[va[i] + 1];
    }
  }
  for (int i = 1; i <= m; ++i) {
    int sum1 = check(i, 1), sum0 = check(i, 0);
    if (sum1 < sum0)
      ans1[i] = 1;
    else
      ans1[i] = 0;
    if (sum1 > sum0)
      ans2[i] = 1;
    else
      ans2[i] = 0;
  }
  for (int i = 1; i <= m; ++i) printf("%d", ans1[i]);
  puts("");
  for (int i = 1; i <= m; ++i) printf("%d", ans2[i]);
  puts("");
  getchar();
  getchar();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct str {
  char s[15];
  str() { memset(s, 0, sizeof(s)); }
  bool operator<(const str &T) const {
    int len = min(strlen(s), strlen(T.s));
    for (int i = 0; i < len; i++)
      if (s[i] != T.s[i]) return s[i] < T.s[i];
    return strlen(s) < strlen(T.s);
  }
} first, second, z;
struct op {
  int idx, idy, idz;
  char optr;
} T;
vector<op> a;
int n, m, mn[1055], mx[1055], num[5055][1055], sz;
char optr[10], s[1055];
map<str, int> M;
int getId(str u) {
  if (u.s[0] == '?') return -1;
  if (!M[u]) M[u] = ++sz;
  return M[u];
}
int getResult(int ind, int bit) {
  for (int i = 0; i < a.size(); i++) {
    op W = a[i];
    int Y, Z;
    if (W.idy == -1)
      Y = bit;
    else
      Y = num[W.idy][ind];
    if (W.idz == -1)
      Z = bit;
    else
      Z = num[W.idz][ind];
    if (W.optr == 'A') num[W.idx][ind] = Y & Z;
    if (W.optr == 'O') num[W.idx][ind] = Y | Z;
    if (W.optr == 'X') num[W.idx][ind] = Y ^ Z;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) res += num[i][ind];
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    first = str();
    second = str();
    memset(s, 0, sizeof(s));
    scanf("%s := %s", first.s, s);
    int idx = getId(first);
    if (s[0] == '0' || s[0] == '1') {
      for (int i = 0; i < m; i++) num[idx][i] = s[i] - '0';
    } else {
      scanf(" %s %s", optr, z.s);
      for (int i = 0; i < 15; i++) second.s[i] = s[i];
      int idy = getId(second);
      int idz = getId(z);
      T.idx = idx;
      T.idy = idy;
      T.idz = idz;
      T.optr = optr[0];
      a.push_back(T);
    }
  }
  for (int i = 0; i < m; i++) {
    int first = getResult(i, 0);
    int second = getResult(i, 1);
    if (first < second) {
      mn[i] = 0;
      mx[i] = 1;
    } else if (first > second) {
      mn[i] = 1;
      mx[i] = 0;
    } else {
      mn[i] = mx[i] = 0;
    }
  }
  for (int i = 0; i < m; i++) printf("%d", mn[i]);
  printf("\n");
  for (int i = 0; i < m; i++) printf("%d", mx[i]);
  printf("\n");
  return 0;
}

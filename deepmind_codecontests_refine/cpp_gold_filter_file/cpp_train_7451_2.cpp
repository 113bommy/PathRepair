#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
map<string, int> mymap;
int n, m, q;
int par[N];
int _find(int r) {
  if (par[r] == r)
    return r;
  else {
    return par[r] = _find(par[r]);
  }
}
int main() {
  n = in(), m = in(), q = in();
  int value = 0;
  for (int i = 1; i <= n; i++) {
    char s[30];
    scanf("%s", s);
    mymap[s] = ++value;
  }
  for (int i = 1; i <= n + n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int ty = in();
    if (ty == 1) {
      char a[30], b[30];
      scanf("%s %s", a, b);
      int _a = mymap[a];
      int _b = mymap[b];
      if (_find(_a) == _find(_b + n) || _find(_a + n) == _find(_b)) {
        puts("NO");
      } else {
        puts("YES");
        par[_find(_a)] = _find(_b);
        par[_find(_a + n)] = _find(_b + n);
      }
    } else {
      char a[30], b[30];
      scanf("%s %s", a, b);
      int _a = mymap[a];
      int _b = mymap[b];
      if (_find(_a) == _find(_b) || _find(_a + n) == _find(_b + n)) {
        puts("NO");
      } else {
        puts("YES");
        par[_find(_a)] = _find(_b + n);
        par[_find(_b)] = _find(_a + n);
      }
    }
  }
  while (q--) {
    char a[30], b[30];
    scanf("%s %s", a, b);
    int _a = mymap[a];
    int _b = mymap[b];
    if (_find(_a) == _find(_b))
      puts("1");
    else if (_find(_a) == _find(_b + n) || _find(_a + n) == _find(_b)) {
      puts("2");
    } else {
      puts("3");
    }
  }
  return 0;
}

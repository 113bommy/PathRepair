#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int x[N], y[N];
struct cmpx {
  bool operator()(const int &a, const int &b) {
    return x[a] == x[b] ? y[a] < y[b] : x[a] < x[b];
  }
};
struct cmpy {
  bool operator()(const int &a, const int &b) {
    return y[a] == y[b] ? x[a] < x[b] : y[a] < y[b];
  }
};
inline int solve(set<int, cmpx> &X, set<int, cmpy> &Y) {
  int n = X.size(), i, t;
  set<int>::iterator Lx, Ly, Rx, Ry;
  set<int, cmpx> XX;
  set<int, cmpy> YY;
  Lx = X.begin();
  Ly = Y.begin();
  Rx = --X.end();
  Ry = --Y.end();
  for (i = 1; i <= n / 2; i++) {
    if (x[*Lx] + 1 < x[*++Lx]) {
      for (--Lx; i--;)
        t = *Lx--, X.erase(t), Y.erase(t), XX.insert(t), YY.insert(t);
      return solve(XX, YY) + solve(X, Y);
    }
    if (y[*Ly] + 1 < y[*++Ly]) {
      for (--Ly; i--;)
        t = *Ly--, X.erase(t), Y.erase(t), XX.insert(t), YY.insert(t);
      return solve(XX, YY) + solve(X, Y);
    }
    if (x[*Rx] - 1 > x[*--Rx]) {
      for (++Rx; i--;)
        t = *Rx++, X.erase(t), Y.erase(t), XX.insert(t), YY.insert(t);
      return solve(XX, YY) + solve(X, Y);
    }
    if (y[*Ry] - 1 > y[*--Ry]) {
      for (--Ry; i--;)
        t = *Ry++, X.erase(t), Y.erase(t), XX.insert(t), YY.insert(t);
      return solve(XX, YY) + solve(X, Y);
    }
  }
  return 1;
}
int main() {
  int n = gi(), i;
  set<int, cmpx> X;
  set<int, cmpy> Y;
  for (i = 1; i <= n; i++) x[i] = gi(), y[i] = gi(), X.insert(i), Y.insert(i);
  printf("%d\n", solve(X, Y));
  return 0;
}

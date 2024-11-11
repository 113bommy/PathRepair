#include <bits/stdc++.h>
using namespace std;
const int inf = 2009;
struct nod {
  int n, idx;
  bool is;
} num[inf];
bool operator<(nod a1, nod a2) {
  if (a1.n == a2.n) {
    if (a1.is == a2.is) return a1.idx < a2.idx;
    return !a1.is;
  }
  return a1.n < a2.n;
}
int st[inf];
bool vis[inf];
int sol[inf];
int csol = 0;
int main() {
  int n, a, b, cp = 0, sel = -1, mn = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    num[cp].n = a;
    num[cp].idx = i;
    num[cp++].is = false;
    num[cp].n = b;
    num[cp].idx = i;
    num[cp++].is = true;
  }
  sort(num, num + cp);
  for (int i = 0; i < cp; ++i) {
    if (num[i].is) {
      if (vis[num[i].idx]) continue;
      sol[csol++] = num[i].n;
      while (mn < sel) vis[st[mn++]] = true;
    } else
      st[sel++] = num[i].idx;
  }
  printf("%d\n", csol);
  for (int i = 0; i < csol; ++i) printf("%d ", sol[i]);
  printf("\n");
}

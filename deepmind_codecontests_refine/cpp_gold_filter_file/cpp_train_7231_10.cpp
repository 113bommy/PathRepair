#include <bits/stdc++.h>
using namespace std;
const int OO = 2e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
struct st {
  int x, p;
  bool operator<(st &y) { return x < y.x; }
};
struct music {
  int l, r, p;
  bool operator<(music &y) { return l < y.l; }
};
bool cmpA(st x, st y) { return x < y; }
bool cmpM(music x, music y) { return x < y; }
int BIT[N], k[N], res[N], n, nm, pR[N];
bool exist[N];
st L[N], R[N];
music M[N];
void uBIT(int i, int v) {
  while (i <= nm) {
    BIT[i] += v;
    i += i & -i;
  }
}
int fBIT(int i) {
  int res = 0;
  while (i > 0) {
    res += BIT[i];
    i -= i & -i;
  }
  return res;
}
int BS1(int v) {
  int l = 1, r = nm, m, res = nm + 1;
  while (l <= r) {
    m = (l + r) / 2;
    if (R[m].x >= v)
      res = m, r = m - 1;
    else
      l = m + 1;
  }
  return res;
}
int BS2(int v) {
  int l = v, r = nm, m, fL, fM, res = 0;
  while (l <= r) {
    m = (l + r) / 2;
    fL = fBIT(l - 1);
    fM = fBIT(m);
    if (exist[m])
      res = m, r = m - 1;
    else if (fM - fL == 0)
      l = m + 1;
    else
      r = m - 1;
  }
  return res;
}
int main() {
  int i, pos = 1, f;
  scanf("%i", &n);
  for (i = 1; i <= n; i++) scanf("%i%i", &M[i].l, &M[i].r), M[i].p = i;
  scanf("%i", &nm);
  for (i = 1; i <= nm; i++)
    scanf("%i%i%i", &L[i].x, &R[i].x, &k[i]), L[i].p = i, R[i].p = i;
  sort(M + 1, M + n + 1, cmpM);
  sort(L + 1, L + nm + 1, cmpA);
  sort(R + 1, R + nm + 1, cmpA);
  for (i = 1; i <= nm; i++) pR[R[i].p] = i;
  memset(BIT, 0, sizeof(BIT));
  memset(exist, false, sizeof(exist));
  for (i = 1; i <= n; i++) {
    while ((pos <= nm) && (L[pos].x <= M[i].l)) {
      uBIT(pR[L[pos].p], 1);
      exist[pR[L[pos].p]] = true;
      pos++;
    }
    f = BS2(BS1(M[i].r));
    if (f == 0) {
      cout << "NO";
      return 0;
    }
    res[M[i].p] = R[f].p;
    k[R[f].p]--;
    if (k[R[f].p] == 0) uBIT(f, -1), exist[f] = false;
  }
  cout << "YES" << endl;
  for (i = 1; i <= n; i++) printf("%i ", res[i]);
}

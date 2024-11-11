#include <bits/stdc++.h>
using namespace std;
const int N = 600010;
int n, m, C, L[N], R[N], co[N], Free, Single[N], tot, sum[N], mx, Ans[N],
    Longest[N], f[N], xx[N], sc;
map<int, int> Double[N], Id_c;
set<int> Show, cc;
set<int>::iterator p, q;
struct Data {
  int x, opt, y;
} A[N];
struct Query {
  int x, Id;
} B[N];
bool operator<(Data a, Data b) { return a.x < b.x; }
bool operator<(Query a, Query b) { return a.x < b.x; }
void Add(int x, int y) {
  for (; x <= sc; x += x & -x) f[x] = max(f[x], y);
}
int Ask(int x) {
  int k = 0;
  for (; x; x -= x & -x) k = max(k, f[x]);
  return k;
}
int main() {
  scanf("%d%d", &n, &C);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &L[i], &R[i], &co[i]);
    A[i * 2 - 1].x = L[i];
    A[i * 2 - 1].opt = 1;
    A[i * 2 - 1].y = i;
    A[i * 2].x = R[i];
    A[i * 2].opt = 0;
    A[i * 2].y = i;
    cc.insert(co[i]);
  }
  for (p = cc.begin(); p != cc.end(); p++) Id_c[*p] = ++sc;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &B[i].x);
    B[i].Id = i;
  }
  sort(A + 1, A + 2 * n + 1);
  sort(B + 1, B + m + 1);
  int j = 1;
  for (int i = 1, la = 0; i <= 2 * n && j <= m; i++)
    if (i == 2 * n || A[i].x < A[i + 1].x) {
      int len = A[i].x - la;
      if (!Show.size())
        Free += len;
      else if (Show.size() == 1) {
        p = Show.begin();
        if (co[*p] <= C) {
          Single[*p] += len;
          Longest[*p] += len;
          mx = max(mx, Longest[*p]);
          q = cc.upper_bound(C - co[*p]);
          mx = max(mx, Single[*p] + Ask((q != cc.end() ? Id_c[*q] - 1 : sc)));
        }
      } else if (Show.size() == 2) {
        q = p = Show.begin();
        q++;
        if (co[*p] + co[*q] <= C) {
          int Id;
          if (!Double[*p][*q]) {
            Id = Double[*q][*p] = Double[*p][*q] = ++tot;
            sum[tot] = Single[*p] + Single[*q] + len;
          } else
            sum[Id = Double[*p][*q]] += len;
          Longest[*p] = max(Longest[*p], sum[Id]);
          Longest[*q] = max(Longest[*q], sum[Id]);
          mx = max(mx, sum[Id]);
        }
      }
      for (; j <= m && B[j].x <= mx + Free; j++)
        Ans[B[j].Id] = A[i].x - (mx + Free - B[j].x);
      la = A[i].x;
      for (int k = i; k && A[k].x == la; k--)
        if (A[k].opt) {
          Show.insert(A[k].y);
        } else {
          p = Show.find(A[k].y);
          Show.erase(p);
          Add(Id_c[co[A[k].y]], Single[A[k].y]);
        }
    }
  for (; j <= m; j++) Ans[B[j].Id] = A[2 * n].x + B[j].x - (mx + Free);
  for (int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
  return 0;
}

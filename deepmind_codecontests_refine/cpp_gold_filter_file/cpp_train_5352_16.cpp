#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, VM = 1e5 + 3, Q = 1e5 + 5, RAD = 316;
int v[N], lst[VM], nxt1[N], nxt2[N], tilgd1[N], tilgd2[N], f[N], ans[Q];
int n, frec(0), gotany(0), cdr, cst;
pair<pair<int, int>, int> qry[Q];
void precalc() {
  for (int i = n; i >= 1; --i) {
    if (lst[v[i]] != 0)
      nxt1[i] = lst[v[i]];
    else
      nxt1[i] = n + 1;
    lst[v[i]] = i;
  }
  for (int i = n; i >= 1; --i) {
    if (nxt1[i] == n + 1 || nxt1[nxt1[i]] == n + 1)
      tilgd1[i] = n + 1;
    else if (i - nxt1[i] != nxt1[i] - nxt1[nxt1[i]])
      tilgd1[i] = nxt1[nxt1[i]] - 1;
    else
      tilgd1[i] = tilgd1[nxt1[i]];
  }
  memset(lst, 0, sizeof lst);
  for (int i = 1; i <= n; ++i) {
    if (lst[v[i]] != 0)
      nxt2[i] = lst[v[i]];
    else
      nxt2[i] = 0;
    lst[v[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (nxt2[i] == 0 || nxt2[nxt2[i]] == 0)
      tilgd2[i] = 0;
    else if (i - nxt2[i] != nxt2[i] - nxt2[nxt2[i]])
      tilgd2[i] = nxt2[nxt2[i]] + 1;
    else
      tilgd2[i] = tilgd2[nxt2[i]];
  }
}
void baga1(int poz) {
  ++f[v[poz]];
  frec += (f[v[poz]] == 1);
  if (f[v[poz]] == 1)
    ++gotany;
  else if (tilgd1[nxt1[poz]] >= cdr && tilgd1[poz] < cdr)
    --gotany;
}
void scoate1(int poz) {
  --f[v[poz]];
  frec -= (f[v[poz]] == 0);
  if (f[v[poz]] == 0)
    --gotany;
  else if (tilgd1[poz] < cdr && tilgd1[nxt1[poz]] >= cdr)
    ++gotany;
}
void baga2(int poz) {
  ++f[v[poz]];
  frec += (f[v[poz]] == 1);
  if (f[v[poz]] == 1)
    ++gotany;
  else if (tilgd2[nxt2[poz]] <= cst && tilgd2[poz] > cst)
    --gotany;
}
void scoate2(int poz) {
  --f[v[poz]];
  frec -= (f[v[poz]] == 0);
  if (f[v[poz]] == 0)
    --gotany;
  else if (tilgd2[poz] > cst && tilgd2[nxt2[poz]] <= cst)
    ++gotany;
}
int main() {
  int q;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  precalc();
  cin >> q;
  for (int i = 0; i < q; ++i)
    cin >> qry[i].first.first >> qry[i].first.second, qry[i].second = i;
  sort(qry, qry + q,
       [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) -> bool {
         if (a.first.first / RAD == b.first.first / RAD)
           return a.first.second < b.first.second;
         return a.first.first < b.first.first;
       });
  cst = qry[0].first.second, cdr = qry[0].first.second - 1;
  for (int i = 0; i < q; ++i) {
    while (qry[i].first.first > cst) scoate1(cst++);
    while (qry[i].first.first < cst) baga1(--cst);
    while (qry[i].first.second > cdr) baga2(++cdr);
    while (qry[i].first.second < cdr) scoate2(cdr--);
    ans[qry[i].second] = frec - (gotany > 0);
  }
  for (int i = 0; i < q; ++i) cout << ++ans[i] << '\n';
  return 0;
}

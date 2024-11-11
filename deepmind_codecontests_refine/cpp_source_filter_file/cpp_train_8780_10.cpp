#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[200005], B[200005], PB[200005], V[200005], tree[200005];
unsigned long long t1[4 * 200005], pot[200005], t2[4 * 200005];
void build(int nodo, int tl, int tr) {
  if (tl == tr) {
    t1[nodo] = V[B[tl]];
    t2[nodo] = V[B[tl]] * B[tl];
    return;
  }
  int mid = (tl + tr) / 2;
  build(nodo * 2, tl, mid);
  build(nodo * 2 + 1, mid + 1, tr);
  t1[nodo] = t1[nodo * 2] + t1[nodo * 2 + 1];
  t2[nodo] = t2[nodo * 2] + t2[nodo * 2 + 1] * pot[t1[2 * nodo]];
}
void update(int nodo, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t1[nodo] = val;
    t2[nodo] = val * B[tl];
    return;
  }
  int mid = (tl + tr) / 2;
  if (mid >= pos)
    update(2 * nodo, tl, mid, pos, val);
  else
    update(2 * nodo + 1, mid + 1, tr, pos, val);
  t1[nodo] = t1[nodo * 2] + t1[nodo * 2 + 1];
  t2[nodo] = t2[nodo * 2] + t2[nodo * 2 + 1] * pot[t1[2 * nodo]];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= m; i++) {
    cin >> B[i];
    PB[B[i]] = i;
  }
  unsigned long long aum = 0, hasha = 0, b = 1;
  pot[0] = 1;
  for (int i = 1; i < n; i++) pot[i] = pot[i - 1] * 200005;
  for (int i = n; i >= 1; i--)
    hasha += b * A[i], aum += b, V[A[i]] = 1, b *= 200005;
  build(1, 1, m);
  int ct = 0;
  for (int d = 0; d <= m - n; d++) {
    if (hasha == t2[1]) ct++;
    if (d == m - n) break;
    hasha += aum;
    update(1, 1, m, PB[1 + d], 0);
    update(1, 1, m, PB[n + 1 + d], 1);
  }
  cout << ct << endl;
}

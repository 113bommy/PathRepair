#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 58, SQ = 500;
int LE[maxn], LO[maxn], par[maxn], a[maxn], root[maxn], lazy[maxn], m;
inline void make(int j) {
  int lase = -1, laso = -1;
  int l = j * SQ;
  for (int i = l; i - l < SQ; i++) {
    a[i] ^= lazy[j];
    if (a[i])
      laso = i;
    else
      lase = i;
    LE[i] = lase;
    LO[i] = laso;
    if (i - l >= m + 1) {
      if (a[i])
        par[i] = LO[i - (m + 1)];
      else
        par[i] = LE[i - (m + 1)];
    } else
      par[i] = -1;
    if (par[i] == -1)
      root[i] = i;
    else
      root[i] = root[par[i]];
  }
  lazy[j] = 0;
}
inline int getlast(int r) {
  while ((lazy[r / SQ] && (LE[r] == -1 || LE[r] / SQ != r / SQ)) ||
         (!lazy[r / SQ] && (LO[r] == -1 || LO[r] / SQ != r / SQ))) {
    r = r / SQ * SQ - 1;
  }
  if (lazy[r / SQ]) return LE[r];
  return LO[r];
}
inline bool P(int r, int l) {
  while (r / SQ > l / SQ) {
    r = root[r];
    r = getlast(r - m - 1);
  }
  while (r > l) {
    r = par[r];
  }
  return r == l;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> m >> q;
  int lase = -1, laso = -1;
  for (int i = 0; i < n; i++) {
    long long b;
    cin >> b;
    b &= 1;
    a[i] = b;
    if (b)
      laso = i;
    else
      lase = i;
    LE[i] = lase;
    LO[i] = laso;
    if (i % SQ >= m + 1) {
      if (b)
        par[i] = LO[i - (m + 1)];
      else
        par[i] = LE[i - (m + 1)];
      if (par[i] == -1 || par[i] / SQ < i / SQ) par[i] = -1;
    } else
      par[i] = -1;
    if (par[i] == -1)
      root[i] = i;
    else
      root[i] = root[par[i]];
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      long long d;
      cin >> l >> r >> d;
      d &= 1;
      l--;
      r--;
      if (!d) continue;
      for (int i = l / SQ + 1; i < r / SQ; i++) {
        lazy[i] ^= 1;
      }
      if (l / SQ != r / SQ) {
        for (int i = l; i / SQ == l / SQ; i++) {
          a[i] ^= 1;
        }
        for (int i = r / SQ * SQ; i <= r; i++) {
          a[i] ^= 1;
        }
        make(l / SQ);
        make(r / SQ);
      } else {
        for (int i = l; i <= r; i++) {
          a[i] ^= 1;
        }
        make(l / SQ);
      }
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      if (a[l] == lazy[l / SQ]) {
        cout << "1\n";
        continue;
      }
      int x = getlast(r);
      if (P(x, l))
        cout << "2\n";
      else
        cout << "1\n";
    }
  }
}

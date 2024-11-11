#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int NMAX = 100000;
const int VALMAX = 100000;
const int BUCKSZ = 3200;
const int NUMBUCKS = NMAX / BUCKSZ;
int N, M;
int belong[NMAX + 5];
int A[NMAX + 5];
struct DSU {
  int T[VALMAX + 5];
  int W[VALMAX + 5];
  void init() {
    memset(T, 0, sizeof(T));
    memset(W, 0, sizeof(W));
  }
  int fi(int nod) {
    if (!T[nod]) {
      return nod;
    }
    return T[nod] = fi(T[nod]);
  }
  void merge(int x, int y) {
    x = fi(x);
    y = fi(y);
    if (x != y) {
      T[x] = y;
      W[y] += W[x];
      W[x] = 0;
    }
  }
};
struct BUCKET {
  DSU fr;
  int OFF;
  int maxval;
  void init() {
    fr.init();
    OFF = maxval = 0;
  }
  void build(int st, int dr) {
    for (int i = st; i <= dr; i++) {
      fr.W[A[i]]++;
      maxval = max(maxval, A[i]);
    }
  }
  void updateWhole(int x) {
    if (2 * x <= maxval) {
      for (int i = OFF + 1; i <= OFF + x; i++) {
        fr.merge(i, i + x);
      }
      OFF += x;
    } else {
      for (int i = maxval; i > x + OFF; i--) {
        fr.merge(i, i - x);
      }
      maxval = min(maxval, OFF + x);
    }
  }
  void updateSingle(int pos, int x) {
    if (fr.fi(A[pos]) - OFF > x) {
      fr.W[fr.fi(A[pos])]--;
      A[pos] -= x;
      fr.W[fr.fi(A[pos])]++;
    }
  }
  int queryWhole(int x) {
    if (x + OFF <= VALMAX) {
      return fr.W[x + OFF];
    }
    return 0;
  }
  int querySingle(int pos, int x) {
    if (fr.fi(A[pos]) - OFF == x) {
      return 1;
    }
    return 0;
  }
} V[NUMBUCKS + 5];
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    belong[i] = (i - 1) / BUCKSZ + 1;
  }
  for (int st = 1, i = 1; st <= N; st += BUCKSZ, i++) {
    V[i].build(st, min(N, st + BUCKSZ - 1));
  }
  while (M--) {
    int t, l, r, x;
    cin >> t >> l >> r >> x;
    int p = belong[l];
    int q = belong[r];
    if (t == 1) {
      for (int i = p + 1; i <= q - 1; i++) {
        V[i].updateWhole(x);
      }
      if (p != q) {
        for (int i = p * BUCKSZ; i >= l; i--) {
          V[p].updateSingle(i, x);
        }
        for (int i = q * BUCKSZ - BUCKSZ + 1; i <= r; i++) {
          V[q].updateSingle(i, x);
        }
      } else {
        for (int i = l; i <= r; i++) {
          V[p].updateSingle(i, x);
        }
      }
    } else {
      int rez = 0;
      for (int i = p + 1; i <= q - 1; i++) {
        rez += V[i].queryWhole(x);
      }
      if (p != q) {
        for (int i = p * BUCKSZ; i >= l; i--) {
          rez += V[p].querySingle(i, x);
        }
        for (int i = q * BUCKSZ - BUCKSZ + 1; i <= r; i++) {
          rez += V[q].querySingle(i, x);
        }
      } else {
        for (int i = l; i <= r; i++) {
          rez += V[p].querySingle(i, x);
        }
      }
      cout << rez << "\n";
    }
  }
  return 0;
}

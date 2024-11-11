#include <bits/stdc++.h>
using namespace std;
struct matrix {
  long long M[2][2];
  matrix(bool identity = 0) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        M[i][j] = 0;
      }
    }
    if (identity) {
      for (int i = 0; i < 2; i++) {
        M[i][i] = 1;
      }
    }
  }
};
matrix operator*(const matrix &A, const matrix &B) {
  matrix tmp;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        tmp.M[i][j] += A.M[i][k] * B.M[k][j] % 1000000007;
        if (tmp.M[i][j] >= 1000000007) tmp.M[i][j] -= 1000000007;
      }
    }
  }
  return tmp;
}
matrix operator+(const matrix &A, const matrix &B) {
  matrix tmp;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tmp.M[i][j] = A.M[i][j] + B.M[i][j];
      if (tmp.M[i][j] >= 1000000007) tmp.M[i][j] -= 1000000007;
    }
  }
  return tmp;
}
long long trace(const matrix &A) {
  long long sm = 0;
  for (int i = 0; i < 2; i++) {
    sm += A.M[i][i];
    if (sm >= 1000000007) sm -= 1000000007;
  }
  return sm;
}
matrix power(matrix a, long long b) {
  matrix x(1);
  while (b) {
    if ((1 & b)) x = x * a;
    a = a * a;
    b >>= 1;
  }
  return x;
}
bool operator!=(const matrix &A, const matrix &B) {
  bool ans = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (A.M[i][j] != B.M[i][j]) {
        ans = 0;
        break;
      }
    }
  }
  return ans;
}
int a[100005];
matrix segt[100005 << 2];
matrix lazy[100005 << 2];
matrix base, id(1), empty;
inline void Merge(const int &t, const int &left, const int &right) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      segt[t].M[i][j] = segt[left].M[i][j] + segt[right].M[i][j];
      if (segt[t].M[i][j] >= 1000000007) segt[t].M[i][j] -= 1000000007;
    }
  }
}
void build(int t, int i, int j) {
  if (i == j) {
    segt[t] = power(base, a[i]);
    return;
  }
  int mid = (i + j) >> 1, left = t << 1, right = left | 1;
  build(left, i, mid);
  build(right, mid + 1, j);
  Merge(t, left, right);
}
void split(const int &t, const int &i, const int &j) {
  segt[t] = segt[t] * lazy[t];
  int left = t << 1, right = left | 1;
  if (i != j) {
    lazy[left] = lazy[left] * lazy[t];
    lazy[right] = lazy[right] * lazy[t];
  }
  lazy[t] = id;
}
matrix upd;
void update(int t, int i, int j, const int &ri, const int &rj) {
  int left = t << 1, right = left | 1, mid = (i + j) >> 1;
  if (lazy[t] != id) {
    split(t, i, j);
  }
  if (i > j || i > rj || j < ri) return;
  if (ri <= i && j <= rj) {
    lazy[t] = upd;
    split(t, i, j);
    return;
  }
  update(left, i, mid, ri, rj);
  update(right, mid + 1, j, ri, rj);
  Merge(t, left, right);
  return;
}
int query(int t, int i, int j, const int &ri, const int &rj) {
  int left = t << 1, right = left | 1, mid = (i + j) >> 1;
  if (lazy[t] != id) {
    split(t, i, j);
  }
  if (i > j || i > rj || j < ri) return 0;
  if (ri <= i && j <= rj) return segt[t].M[1][0];
  int x1 = 0, x2 = 0;
  x1 = query(left, i, mid, ri, rj);
  x2 = query(right, mid + 1, j, ri, rj);
  Merge(t, left, right);
  x1 += x2;
  if (x1 >= 1000000007) x1 -= 1000000007;
  return x1;
}
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  base.M[0][0] = base.M[0][1] = base.M[1][0] = 1;
  build(1, 1, n);
  for (int i = 1; i <= (n << 2); i++) lazy[i] = id;
  while (m--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d", &l);
      scanf("%d", &r);
      scanf("%d", &x);
      upd = power(base, x);
      update(1, 1, n, l, r);
    } else {
      int l, r;
      scanf("%d", &l);
      scanf("%d", &r);
      printf("%d\n", query(1, 1, n, l, r));
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
const long double PI = acosl(-1.0);
const double EPS = 1e-12;
void combination(long long com[][1005]) {
  com[0][0] = 1;
  int sz = 1000;
  for (int i = 1; i <= sz; i++) {
    com[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      com[i][j] = com[i - 1][j] + com[i - 1][j - 1];
      com[i][j] = com[i][j] % 1000000007;
    }
  }
}
int find_par(int cn) {}
int gcd(int u, int v) {
  if (v == 0) return u;
  return gcd(v, u % v);
}
void insert_ind(int cs, int ci, int s, int e) {
  if (s == e) {
    return;
  }
  int mid = (s + e) / 2;
  if (ci <= mid)
    insert_ind(2 * cs, ci, s, mid);
  else
    insert_ind(2 * cs + 1, ci, mid + 1, e);
}
void update_ind(int cs, int ci, int s, int e, int val) {
  if (s == e) {
    return;
  }
  int mid = (s + e) / 2;
  if (ci <= mid)
    update_ind(2 * cs, ci, s, mid, val);
  else
    update_ind(2 * cs + 1, ci, mid + 1, e, val);
}
void update_seg(int cs, int ds, int de, int s, int e, int val) {
  if (ds == s && de == e) {
    return;
  }
  int mid = (s + e) / 2;
  if (ds <= mid) update_seg(2 * cs, ds, min(mid, de), s, mid, val);
  if (de > mid) update_seg(2 * cs + 1, max(mid + 1, ds), de, mid + 1, e, val);
}
void pattern_match(char pat[], const int len, int pi[]) {
  pi[1] = 0;
  for (int i = 2; i <= len; i++) {
    int st = i - 1;
    while (st >= 0 && pat[pi[st] + 1] != pat[i]) st = pi[st];
    if (st == 0)
      pi[i] = 0;
    else
      pi[i] = pi[st] + 1;
  }
}
void pattern_match(char pat[], int pi[], char tar[], const int len1, int gi[]) {
  if (pat[0] == tar[0]) gi[0] = 1;
  for (int i = 1; i < len1; i++) {
    int st = gi[i - 1];
    while (pat[st] != tar[i]) {
      if (st == 0) {
        st = -1;
        break;
      }
      st = pi[st - 1];
    }
    if (st == -1)
      gi[i] = 0;
    else
      gi[i] = st + 1;
  }
}
struct myArray {
  int mat[10][10];
};
myArray matrix_mul(myArray mat1, myArray mat2, const int sz) {
  int tmp[sz][sz];
  memset((tmp), 0, sizeof((tmp)));
  for (int r = 0; r < sz; r++)
    for (int c = 0; c < sz; c++)
      for (int cr = 0; cr < sz; cr++)
        tmp[r][c] += mat1.mat[r][cr] * mat2.mat[c][cr];
  myArray res;
  for (int r = 0; r < sz; r++)
    for (int c = 0; c < sz; c++) res.mat[r][c] = tmp[r][c];
  return res;
}
myArray unit_matrix(const int sz) {
  myArray ma;
  memset((ma.mat), 0, sizeof((ma.mat)));
  for (int i = 0; i < sz; i++) ma.mat[i][i] = 1;
  return ma;
}
myArray matrix_expo(int p, myArray mat, const int sz) {
  if (p == 0) {
    return unit_matrix(sz);
  }
  if (p & 1) return matrix_mul(mat, matrix_expo(p - 1, mat, sz), sz);
  myArray tmp = matrix_expo(p >> 1, mat, sz);
  return matrix_mul(tmp, tmp, sz);
}
int n, m;
void row() {
  cout << "1 1" << endl;
  for (int i = 1; i <= n; i++)
    if ((i - 1) % 2 == 0)
      for (int j = 2; j <= m; j++) cout << i << " " << j << endl;
    else
      for (int j = m; j >= 2; j--) cout << i << " " << j << endl;
  for (int i = n; i >= 1; i--) cout << i << " " << 1 << endl;
}
void col() {
  cout << "1 1" << endl;
  for (int i = 1; i <= m; i++)
    if ((i - 1) % 2 == 0)
      for (int j = 2; j <= n; j++) cout << j << " " << i << endl;
    else
      for (int j = n; j >= 2; j--) cout << j << " " << i << endl;
  for (int i = m; i >= 1; i--) cout << 1 << " " << i << endl;
}
int main() {
  cin >> n >> m;
  if ((n * m % 2) == 0 && !(n + m > 3 && (n == 1 || m == 1))) {
    cout << 0 << endl;
    if (n % 2 == 0)
      row();
    else
      col();
  } else {
    cout << 1 << endl;
    cout << n << " " << m << " " << 1 << " " << 1 << endl;
    for (int i = 1; i <= n; i++) {
      if (i & 1)
        for (int j = 1; j <= m; j++) cout << i << " " << j << endl;
      else
        for (int j = m; j >= 1; j--) cout << i << " " << j << endl;
    }
    cout << 1 << " " << 1 << endl;
  }
  return 0;
}

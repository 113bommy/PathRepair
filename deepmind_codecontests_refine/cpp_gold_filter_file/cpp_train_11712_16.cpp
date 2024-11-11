#include <bits/stdc++.h>
using namespace std;
const long double PI = acosl(-1.0);
const double EPS = 1e-12;
void showBit(int no, int N) {
  for (int i = N - 1; i >= 0; i--)
    if ((no >> i) & 1)
      printf("1");
    else
      printf("0");
  printf("\n");
}
int binToDec(string s) {
  int ln = s.length();
  int sum = 0;
  for (int i = ln - 1, k = 0; i >= 0; i--, k++)
    sum = sum + (s[i] - '0') * (1 << k);
  return sum;
}
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
map<string, int> msi;
void cal_state(string s, int tran[][30]) {
  int ln = s.length();
  string s1 = s;
  for (int i = 0; i < ln; i++) {
    msi[s1] = ln - i;
    s1 = s1.substr(0, ln - i - 1);
  }
  s1 = "";
  for (int i = 0; i < ln; i++) {
    string ts = s1;
    for (int j = 0; j < 26; j++) {
      s1 = ts + (char)('a' + j);
      int tln = i + 1;
      while (msi[s1] == 0) {
        s1 = s1.substr(1);
        tln--;
        if (tln == 0) break;
      }
      if (tln == 0) s1 = "";
      tran[i][j] = msi[s1];
    }
    s1 = s.substr(0, i + 1);
  }
}
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int r[1005], c[1005];
int main() {
  string s;
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  for (int i = (0); i < (n); ++i) {
    cin >> s;
    cnt = cnt + m;
    for (int j = (0); j < (m); ++j)
      if (s[j] == 'X') {
        cnt--;
        r[i + 1] = j + 1, c[j + 1] = i + 1;
      }
  }
  double dis = 0;
  for (int i = (1); i < (n + 1); ++i) {
    long long tdis = 0;
    for (int j = (i + 1); j < (n + 1); ++j)
      tdis = tdis + (j - i) * (m - (r[j] > 0));
    for (int j = i - 1; j >= 1; j--) tdis = tdis + (i - j) * (m - (r[j] > 0));
    tdis = tdis * (m - (r[i] > 0));
    dis += tdis;
    if (r[i]) {
      tdis = m - r[i];
      int cp = r[i];
      for (int j = i + 1; j <= n && r[j] > cp; cp = r[j++]) tdis += m - r[j];
      cp = r[i];
      for (int j = i - 1; j > 0 && r[j] > cp; cp = r[j--]) tdis += m - r[j];
      dis += tdis * (r[i] - 1) * 4;
    }
  }
  for (int i = (1); i < (m + 1); ++i) {
    long long tdis = 0;
    for (int j = (i + 1); j < (m + 1); ++j)
      tdis = tdis + (j - i) * (n - (c[j] > 0));
    for (int j = i - 1; j > 0; j--) tdis = tdis + (i - j) * (n - (c[j] > 0));
    tdis = tdis * (n - (c[i] > 0));
    dis += tdis;
    if (c[i]) {
      int cp = c[i];
      tdis = n - cp;
      for (int j = i + 1; j <= m && cp < c[j]; cp = c[j++]) tdis += n - c[j];
      cp = c[i];
      for (int j = i - 1; j > 0 && c[j] > cp; cp = c[j--]) tdis += n - c[j];
      dis = dis + tdis * (c[i] - 1) * 4;
    }
  }
  printf("%.12lf\n", dis / cnt / cnt);
  return 0;
}

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
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
map<string, int> msi;
void cal_state(string s, int tran[][30]) {
  int ln = s.length();
  string s1 = s;
  for (int i = 0; i < ln; i++) {
    msi[s1] = ln - i;
    s1 = s1.substr(0, ln - i - 1);
  }
  s1 = "";
  for (int i = 0; i <= ln; i++) {
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
    if (i < ln) s1 = s.substr(0, i + 1);
  }
}
string s, b;
int tran[105][30];
int n, k;
bool col[105];
bool dp[105][105][105];
int c[105][105][105], ps[105][105][105];
int prp[105][105][105];
void print(int ln, int cs, int rp) {
  if (ln == 0) return;
  print(ln - 1, ps[ln][cs][rp], prp[ln][cs][rp]);
  printf("%c", 'a' + c[ln][cs][rp]);
}
int main() {
  cin >> n >> k;
  cin >> s;
  cal_state(s, tran);
  cin >> b;
  int ln = b.length();
  int cnt = 0;
  for (int i = (0); i < (ln); ++i)
    if (b[i] == '1') col[i] = true, cnt++;
  dp[0][0][0] = true;
  ln = s.length();
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      for (int rp = 0; rp <= cnt; rp++)
        if (dp[i][j][rp]) {
          for (int ne = 0; ne < k; ne++) {
            int ns = tran[j][ne];
            if (ns == ln) {
              if (col[i - ln + 1] && rp + 1 <= k) {
                dp[i + 1][ns][rp + 1] = true;
                c[i + 1][ns][rp + 1] = ne;
                ps[i + 1][ns][rp + 1] = j;
                prp[i + 1][ns][rp + 1] = rp;
              }
            } else {
              dp[i + 1][ns][rp] = true;
              c[i + 1][ns][rp] = ne;
              ps[i + 1][ns][rp] = j;
              prp[i + 1][ns][rp] = rp;
            }
          }
        }
  for (int i = 0; i <= n; i++)
    if (dp[n][i][k] == true) {
      print(n, i, k);
      printf("\n");
      return 0;
    }
  printf("No solution\n");
  return 0;
}

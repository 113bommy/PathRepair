#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
string s, t;
int nxt[maxn], F[30];
string F1, F2, Fs[30];
struct matrix_base {
  int a[2][2];
  matrix_base() { memset(a, 0, sizeof a); }
  void mul() {
    int b[2][2];
    memset(b, 0, sizeof b);
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          b[i][j] = ((long long)a[i][k] * a[k][j] % mod + b[i][j]) % mod;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) a[i][j] = b[i][j];
  }
} bm;
struct matrix_ans {
  int a[2];
  matrix_ans() { memset(a, 0, sizeof a); }
  void mul() {
    int b[2];
    memset(b, 0, sizeof b);
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        b[i] = ((long long)a[j] * bm.a[j][i] % mod + b[i]) % mod;
    for (int i = 0; i < 2; i++) a[i] = b[i];
  }
} ans;
int get_num(const string &a) {
  int res = 0, len = s.length();
  for (int i = 0, j = 0, Len = a.length(); i < Len; i++) {
    while (j >= 0 && t[j + 1] != a[i]) j = nxt[j];
    if (++j == len) res++, j = nxt[j];
  }
  return res;
}
int Main(long long n) {
  cin >> s;
  int len = s.length();
  t = "%" + s;
  nxt[0] = -1;
  for (int i = 2, j = 0; i <= len; i++) {
    while (j >= 0 && t[j + 1] != t[i]) j = nxt[j];
    nxt[i] = ++j;
  }
  int base = 0;
  F[1] = F[2] = 1;
  Fs[1] = "a";
  Fs[2] = "b";
  for (int i = 3;; i++) {
    if (F[i - 2] > len) {
      Fs[i] = Fs[i - 1] + Fs[i - 2];
      base = i - 1;
      break;
    }
    F[i] = F[i - 1] + F[i - 2];
    Fs[i] = Fs[i - 1] + Fs[i - 2];
  }
  string a, b, c;
  for (int i = 0; i < len - 1; i++) a += Fs[base - 1][i];
  for (int i = Fs[base - 1].length() - (len - 1), Len = Fs[base - 1].length();
       i < Len; i++)
    b += Fs[base - 1][i];
  for (int i = Fs[base].length() - (len - 1), Len = Fs[base].length(); i < Len;
       i++)
    c += Fs[base][i];
  int vc = get_num(c + a);
  int vb = get_num(b + a);
  if (n - base <= 1) return get_num(Fs[n]);
  ans.a[0] = 0, ans.a[1] = 1;
  bm.a[0][0] = 0;
  bm.a[0][1] = bm.a[1][0] = bm.a[1][1] = 1;
  long long y = n - base;
  for (int i = 0; (1LL << i) <= y; i++, bm.mul())
    if (y & (1LL << i)) ans.mul();
  int B = ans.a[0] - (y & 1);
  ans.a[0] = 0, ans.a[1] = 1;
  bm.a[0][0] = 0;
  bm.a[0][1] = bm.a[1][0] = bm.a[1][1] = 1;
  for (int i = 0; (1LL << i) <= y - 1; i++, bm.mul())
    if ((y - 1) & (1LL << i)) ans.mul();
  int C = ans.a[0] - ((y - 1) & 1);
  ans.a[0] = get_num(Fs[base]);
  ans.a[1] = get_num(Fs[base] + Fs[base - 1]);
  bm.a[0][0] = 0;
  bm.a[0][1] = bm.a[1][0] = bm.a[1][1] = 1;
  for (int i = 0; (1LL << i) <= y; i++, bm.mul())
    if (y & (1LL << i)) ans.mul();
  int res = ans.a[0];
  res = ((long long)B * vb % mod + (long long)C * vc % mod + res) % mod;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  while (m--) cout << Main(n) << '\n';
  return 0;
}

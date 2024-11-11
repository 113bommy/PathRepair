#include <bits/stdc++.h>
using namespace std;
const int N = 30000, M = 200000, mod = 1000000007;
int add(int a, int b, int p = mod) { return a + b >= p ? a + b - p : a + b; }
int sub(int a, int b, int p = mod) { return a - b < 0 ? a - b + p : a - b; }
int mul(int a, int b, int p = mod) { return 1LL * a * b % p; }
void sadd(int &a, int b, int p = mod) { a = add(a, b, p); }
void ssub(int &a, int b, int p = mod) { a = sub(a, b, p); }
void smul(int &a, int b, int p = mod) { a = mul(a, b, p); }
int Power(int a, int k, int p = mod) {
  int res = 1;
  for (; k; k >>= 1, smul(a, a, p))
    if (k & 1) smul(res, a, p);
  return res;
}
int Get_inv(int a, int p = mod) { return Power(a, p - 2, p); }
struct matrix {
  int a[2][2];
  int *operator[](const int &p) { return a[p]; }
  matrix operator*(const matrix &p) const {
    matrix res = matrix();
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          res.a[i][k] = (res.a[i][k] + 1LL * a[i][j] * p.a[j][k]) % mod;
    return res;
  }
};
matrix Power(matrix a, long long k) {
  matrix res = matrix();
  for (int i = 0; i < 2; ++i) res[i][i] = 1;
  for (; k; k >>= 1, a = a * a)
    if (k & 1) res = res * a;
  return res;
}
matrix Get_fib(long long n) {
  matrix res = matrix();
  res[0][0] = res[0][1] = res[1][0] = 1;
  return Power(res, n);
}
void into() {}
string fib[N + 9];
int len[N + 9], cf;
void Get_fib() {
  fib[1] = "a";
  fib[2] = "b";
  for (int i = 3; 2333; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    len[i] = fib[i].size();
    cf = i;
    if (len[i - 1] >= M) break;
  }
}
void work() { Get_fib(); }
char s[M + 9];
int m, nxt[M + 9];
void KMP() {
  for (int i = 2, j = 0; i <= m; ++i) {
    for (; j && s[j + 1] ^ s[i]; j = nxt[j])
      ;
    nxt[i] = j += s[j + 1] == s[i];
  }
}
int Get_cnt(string str) {
  int res = 0;
  for (int vs = str.size(), i = 0, j = 0; i < vs; ++i) {
    for (; j && s[j + 1] ^ str[i]; j = nxt[j])
      ;
    j += s[j + 1] == str[i];
    if (j == m) ++res, j = nxt[j];
  }
  return res;
}
long long n;
int Get_ans() {
  KMP();
  int p = lower_bound(len + 1, len + cf + 1, m) - len + 1;
  if (p + 1 >= n) return Get_cnt(fib[n]);
  int res = 0;
  string a = fib[p].substr(0, m - 1);
  string b = fib[p].substr(len[p] - m + 1, m - 1);
  string c = fib[p + 1].substr(len[p + 1] - m + 1, m - 1);
  long long t = n - p;
  sadd(res, mul(sub(Get_fib(t)[0][1], t & 1), Get_cnt(c + a)));
  sadd(res, mul(sub(Get_fib(t - 1)[0][1], t & 1 ^ 1), Get_cnt(b + a)));
  matrix tmp = matrix();
  tmp[0][0] = Get_cnt(fib[p + 1]);
  tmp[0][1] = tmp[1][0] = Get_cnt(fib[p]);
  sadd(res, (tmp * Get_fib(t))[0][1]);
  return res;
}
void outo() {
  int cq;
  scanf("%lld%d", &n, &cq);
  for (; cq--;) {
    scanf("%s", s + 1);
    m = strlen(s + 1);
    printf("%d\n", Get_ans());
  }
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}

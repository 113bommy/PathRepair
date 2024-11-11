#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
const int MOD = 1000000007;
const int N = 16;
inline void add(int& x, int y) {
  if ((x += y) >= MOD) x -= MOD;
}
inline void sub(int& x, int y) {
  if ((x -= y) < 0) x += MOD;
}
inline int mult(int x, int y) { return (x * 1LL * y) % MOD; }
void dzeta(vector<int>& x) {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < (1 << N); i++)
      if (i & (1 << k)) add(x[i], x[i ^ (1 << k)]);
}
void undzeta(vector<int>& x) {
  for (int k = 0; k < N; k++)
    for (int i = 0; i < (1 << N); i++)
      if (i & (1 << k)) sub(x[i], x[i ^ (1 << k)]);
}
void reverse(vector<int>& x) {
  for (int i = 0; i < (1 << N); i++) {
    int other = ((1 << N) - 1) ^ i;
    if (i < other) swap(x[i], x[other]);
  }
}
vector<int> calc_or(vector<int> l, vector<int> r) {
  dzeta(l);
  dzeta(r);
  vector<int> result(1 << N);
  for (int i = 0; i < (1 << N); i++) result[i] = mult(l[i], r[i]);
  undzeta(result);
  return result;
}
vector<int> calc_and(vector<int> l, vector<int> r) {
  reverse(l);
  reverse(r);
  vector<int> result = calc_or(l, r);
  reverse(result);
  return result;
}
char s[1000];
int sptr;
vector<int> result_var[9];
vector<int> expr() {
  if (s[sptr] == '(') {
    sptr++;
    vector<int> resleft = expr();
    assert(s[sptr++] == ')');
    char c = s[sptr];
    if (c != '|' && c != '&' && c != '?') {
      return resleft;
    }
    sptr++;
    assert(s[sptr++] == '(');
    vector<int> resright = expr();
    assert(s[sptr++] == ')');
    if (c == '&') {
      return calc_and(resleft, resright);
    }
    if (c == '|') {
      return calc_or(resleft, resright);
    }
    assert(c == '?');
    vector<int> result_and = calc_and(resleft, resright);
    vector<int> result_or = calc_or(resleft, resright);
    for (int i = 0; i < (1 << N); i++) add(result_and[i], result_or[i]);
    return result_and;
  }
  if (s[sptr] == '?') {
    sptr++;
    return result_var[8];
  }
  if ('A' <= s[sptr] && s[sptr] <= 'D') {
    sptr++;
    return result_var[s[sptr - 1] - 'A'];
  }
  assert('a' <= s[sptr] && s[sptr] <= 'd');
  sptr++;
  return result_var[s[sptr - 1] - 'a' + 4];
}
int main() {
  for (int i = 0; i < 4; i++) {
    result_var[i] = vector<int>(1 << N);
    int val = 0;
    for (int j = 0; j < N; j++)
      if (j & (1 << i)) val |= (1 << j);
    result_var[i][val] = 1;
  }
  for (int i = 0; i < 4; i++) {
    result_var[i + 4] = vector<int>(1 << N);
    int val = 0;
    for (int j = 0; j < N; j++)
      if (!(j & (1 << i))) val |= (1 << j);
    result_var[i + 4][val] = 1;
  }
  result_var[8] = result_var[0];
  for (int i = 1; i < 8; i++)
    for (int j = 0; j < (1 << N); j++) add(result_var[8][j], result_var[i][j]);
  fgets(s, sizeof(s), stdin);
  vector<int> res = expr();
  assert(s[sptr] == 0 || s[sptr] == '\r' || s[sptr] == '\n');
  int and_mask, xor_mask;
  and_mask = xor_mask = 0;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b, c, d, val;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &val);
    int pos = a | (b << 1) | (c << 2) | (d << 3);
    and_mask |= (1 << pos);
    xor_mask |= (val << pos);
  }
  int ans = 0;
  for (int i = 0; i < (1 << N); i++)
    if ((i & and_mask) == xor_mask) add(ans, res[i]);
  printf("%d\n", ans);
  return 0;
}

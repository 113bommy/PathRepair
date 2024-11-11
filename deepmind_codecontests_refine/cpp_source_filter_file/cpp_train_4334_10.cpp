#include <bits/stdc++.h>
using namespace std;
const int maxk = 51;
struct matrix {
  bool e[maxk][maxk];
  int sz;
  void print() {
    for (int i = 0, _n = (sz); i < _n; i++) {
      for (int j = 0, _n = (sz); j < _n; j++) {
        printf("%d", e[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
};
matrix operator*(const matrix &A, const matrix &B) {
  matrix ret;
  memset(&ret, 0, sizeof(ret));
  ret.sz = A.sz;
  for (int i = 0, _n = (A.sz); i < _n; i++)
    for (int k = 0, _n = (A.sz); k < _n; k++)
      if (A.e[i][k])
        for (int j = 0, _n = (A.sz); j < _n; j++) ret.e[i][j] ^= B.e[k][j];
  return ret;
}
matrix one;
matrix pow2(matrix M, long long deg) {
  matrix ret;
  memset(&ret, 0, sizeof(ret));
  for (int i = 0, _n = (M.sz); i < _n; i++) ret.e[i][i] = 1;
  ret.sz = M.sz;
  while (deg) {
    if (deg & 1) ret = ret * M;
    M = M * M;
    deg >>= 1;
  }
  return ret;
}
long long my_rand() {
  long long ret = 0;
  for (int i = 0, _n = (4); i < _n; i++) ret = (ret << 15) + rand() % (1 << 15);
  return ret;
}
vector<long long> prime_div;
int check_one(const matrix &tmp) {
  bool zero = 1;
  for (int i = 0, _n = (tmp.sz); i < _n; i++)
    for (int j = 0, _n = (tmp.sz); j < _n; j++)
      if (tmp.e[i][j]) zero = 0;
  if (zero) return 0;
  for (int i = 0, _n = (tmp.sz); i < _n; i++)
    for (int j = 0, _n = (tmp.sz); j < _n; j++)
      if (tmp.e[i][j] != (i == j)) return -1;
  return 1;
}
bool check(long long c, int k) {
  matrix cM;
  memset(&cM, 0, sizeof(cM));
  cM.sz = k;
  for (int i = 0, _n = (k - 1); i < _n; i++) cM.e[i][i + 1] = 1;
  for (int i = 0, _n = (k); i < _n; i++)
    cM.e[k - 1][k - i - 1] = ((c & (1ll << i)) > 0);
  matrix tmp = pow2(cM, (1ll << k) - 1);
  long long m = (1ll << k) - 1;
  if (check_one(tmp) == 1) {
    for (int i = 0, _n = (prime_div.size()); i < _n; i++) {
      tmp = pow2(cM, m / prime_div[i]);
      if (check_one(tmp) != -1) return 0;
    }
    return 1;
  }
  return 0;
}
long long find_ans(int k) {
  prime_div.clear();
  long long m = (1ll << k) - 1;
  for (long long q = 2; q * q <= m; q++) {
    if (m % q == 0) {
      while (m % q == 0) m /= q;
      prime_div.push_back(q);
    }
  }
  if (m > 1) prime_div.push_back(m);
  one.sz = k;
  long long c = 0;
  for (c = ((1ll << k) - 1); !check(c, k); c--)
    ;
  return c;
}
void generate_ans() {
  memset(&one, 0, sizeof(one));
  for (int k = 0, _n = (50); k < _n; k++) one.e[k][k] = 1;
  for (int k = 2, _b = (50); k <= _b; k++) {
    long long c = find_ans(k);
    cout << c << "ll, " << endl;
    fprintf(stderr, "%d\n", k);
  }
}
long long const_ans[51] = {
    0ll,
    0ll,
    3ll,
    5ll,
    9ll,
    18ll,
    33ll,
    65ll,
    142ll,
    264ll,
    516ll,
    1026ll,
    2089ll,
    4109ll,
    8213ll,
    16385ll,
    32790ll,
    65540ll,
    131091ll,
    262163ll,
    524292ll,
    1048578ll,
    2097153ll,
    4194320ll,
    8388621ll,
    16777220ll,
    33554467ll,
    67108883ll,
    134217732ll,
    268435458ll,
    536870953ll,
    1073741828ll,
    2147483735ll,
    4294967337ll,
    8589934707ll,
    17179869186ll,
    34359738427ll,
    68719476767ll,
    137438953521ll,
    274877906952ll,
    549755813916ll,
    1099511627780ll,
    2199023255583ll,
    4398046511148ll,
    8796093022258ll,
    17592186044429ll,
    35184372088983ll,
    70368744177680ll,
    140737488355419ll,
    281474976710712ll,
    562949953421326ll,
};
int k;
int main() {
  scanf("%d", &k);
  const_ans[k] = find_ans(k);
  for (int i = 0, _n = (k); i < _n; i++) {
    if (i) printf(" ");
    printf("%d", (const_ans[k] & (1 << i)) > 0);
  }
  printf("\n");
  for (int i = 0, _n = (k - 1); i < _n; i++) printf("0 ");
  printf("1\n");
  return 0;
}

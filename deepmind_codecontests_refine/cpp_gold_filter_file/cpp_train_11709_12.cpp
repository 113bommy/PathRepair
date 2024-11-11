#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2333;
const int D = 20;
const int M = 1 << D;
const int MAXD = 2333;
char str[MAXN];
int n, tot, special[MAXN], a[MAXN], b[MAXN];
bitset<MAXN> ans, fro, from[MAXN], num[MAXN], table[MAXN];
inline void print(bitset<MAXN> p) {
  for (int i = 20; i >= 0; --i) cout << p[i];
  cout << endl;
}
inline void get_number(int id) {
  num[id].reset();
  scanf("%s", str);
  int len = strlen(str), now = 0;
  for (int i = 0; i < len; ++i) a[i] = str[i] - '0';
  while (len) {
    long long left = 0;
    int l = 0, ps = 0;
    for (int i = 0; i < len; ++i) {
      left = left * 10 + a[i];
      b[l++] = left / M;
      left %= M;
    }
    for (int i = 0; i < D; ++i) num[id][now++] = (left >> i) & 1;
    for (; !b[ps]; ++ps)
      ;
    if (ps >= l) break;
    for (int i = ps; i < l; ++i) a[i - ps] = b[i];
    len = l - ps;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    get_number(i);
  }
  tot = 0;
  for (int i = 0; i < n; ++i) {
    ans.reset();
    fro.reset();
    fro[i] = 1;
    for (int j = 0; j < tot; ++j) {
      if (num[i][special[j]]) {
        num[i] ^= table[j];
        fro ^= from[j];
      }
    }
    int sp = -1;
    for (int j = 0; j < MAXD; ++j)
      if (num[i][j]) {
        sp = j;
        break;
      }
    if (sp == -1) {
      fro[i] = 0;
      printf("%d", fro.count());
      for (int j = 0; j < i; ++j)
        if (fro[j]) printf(" %d", j);
      puts("");
    } else {
      printf("0\n");
      for (int j = 0; j < tot; ++j)
        if (table[j][sp]) {
          table[j] ^= num[i];
          from[j] ^= fro;
        }
      table[tot] = num[i];
      special[tot] = sp;
      from[tot++] = fro;
    }
  }
}

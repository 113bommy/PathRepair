#include <bits/stdc++.h>
using namespace std;
char str[100005];
int n, k;
struct SAM {
  int next[100005 * 2][26], fa[100005 * 2], len[100005 * 2];
  int last, cnt;
  int cntA[100005 * 2], A[100005 * 2];
  long long num[100005 * 2], sz[100005 * 2];
  void clear() {
    last = cnt = 1;
    fa[1] = len[1] = 0;
    memset(next[1], 0, sizeof(next[1]));
  }
  void init(char *s) {
    while (*s) {
      Insert(*s - 'a');
      s++;
    }
  }
  void Insert(int c) {
    int p = last;
    int np = ++cnt;
    memset(next[cnt], 0, sizeof next[cnt]);
    len[np] = len[p] + 1;
    last = np;
    while (p && !next[p][c]) next[p][c] = np, p = fa[p];
    if (!p)
      fa[np] = 1;
    else {
      int q = next[p][c];
      if (len[q] == len[p] + 1)
        fa[np] = q;
      else {
        int nq = ++cnt;
        len[nq] = len[p] + 1;
        memcpy(next[nq], next[q], sizeof(next[q]));
        fa[nq] = fa[q];
        fa[np] = fa[q] = nq;
        while (next[p][c] == q) next[p][c] = nq, p = fa[p];
      }
    }
  }
  void build() {
    memset(cntA, 0, sizeof cntA);
    memset(num, 0, sizeof num);
    for (int i = 1; i <= cnt; i++) cntA[len[i]]++;
    for (int i = 1; i <= n; i++) cntA[i] += cntA[i - 1];
    for (int i = cnt; i >= 1; i--) A[cntA[len[i]]--] = i;
    int tmp = 1;
    for (int i = 0; i < n; i++) {
      num[tmp = next[tmp][str[i] - 'a']] = 1;
    }
    for (int i = cnt; i >= 1; i--) {
      int x = A[i];
      num[fa[x]] += num[x];
    }
    num[1] = 0;
    for (int i = cnt; i >= 1; i--) {
      int x = A[i];
      sz[x] = num[x];
      for (int j = 0; j < 26; j++) {
        if (!next[x][j]) continue;
        sz[x] += sz[next[x][j]];
      }
    }
  }
  void solve(int k) {
    build();
    int now = 1, pos = 0;
    while (k > 0) {
      pos = 0;
      while (pos < 26 && k > sz[next[now][pos]]) {
        k -= sz[next[now][pos]];
        pos++;
      }
      if (pos == 26) {
        puts("No such line.");
        return;
      }
      printf("%c", pos + 'a');
      now = next[now][pos];
      k -= num[now];
    }
  }
} sam;
int main() {
  scanf("%s%d", str, &k);
  n = strlen(str);
  sam.clear();
  sam.init(str);
  sam.solve(k);
  return 0;
}

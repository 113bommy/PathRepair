#include <bits/stdc++.h>
using namespace std;
namespace Base {
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const long long infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
template <typename T>
void read(T &x) {
  x = 0;
  int fh = 1;
  double num = 1.0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  if (ch == '.') {
    ch = getchar();
    while (isdigit(ch)) {
      num /= 10;
      x = x + num * (ch - '0');
      ch = getchar();
    }
  }
  x = x * fh;
}
template <typename T>
void chmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
void chmin(T &x, T y) {
  x = x > y ? y : x;
}
}  // namespace Base
using namespace Base;
const int N = 510;
bool tag[N];
int nxt[N], n, m, len[N], pre[N][N], bak[N][N], now[N], ch[N];
long long k, cnt[N];
void kmp(int *a, int lena, int *b, int lenb) {
  memset(tag, 0, sizeof(tag));
  for (int i = 1; i <= lenb; i++) {
    int p = i - 1;
    while (p != 0 && b[nxt[p] + 1] != b[i]) p = nxt[p];
    if (b[nxt[p] + 1] != a[i] || i == 1)
      nxt[p] = 0;
    else
      nxt[i] = nxt[p] + 1;
  }
  for (int i = 1, j = 1; i <= lena; i++) {
    while (j != 1 && a[i] != b[j]) j = nxt[j - 1] + 1;
    if (a[i] == b[j]) j++;
    if (j > lenb) {
      tag[i] = true, j = nxt[j - 1] + 1;
    }
  }
}
int main() {
  read(n);
  read(k);
  read(m);
  k = k + 1;
  len[0] = len[1] = 1;
  pre[0][1] = 0;
  pre[1][1] = 1;
  bak[0][1] = 0;
  bak[1][1] = 1;
  for (int j = 2; j <= n; j++) {
    for (int k = 1; k <= len[j - 2]; k++) pre[j][k] = pre[j - 2][k];
    if (len[j - 2] < m) {
      for (int k = len[j - 2] + 1; k <= min(len[j - 2] + len[j - 1], m); k++)
        pre[j][k] = pre[j - 1][k - len[j - 2]];
    }
    int tmp = 0;
    if (len[j - 1] < m) {
      tmp = min(len[j - 2], m - len[j - 1]);
      for (int k = 1; k <= tmp; k++)
        bak[j][k] = bak[j - 2][len[j - 2] - tmp + k];
    }
    for (int k = 1; k <= len[j - 1]; k++) bak[j][k + tmp] = bak[j - 1][k];
    len[j] = min(m, len[j - 1] + len[j - 2]);
  }
  for (int i = 1; i <= m; i++) {
    bool flag = false;
    for (int j = 1; j <= i - 1; j++)
      if (bak[n][len[n] - i + j + 1] != ch[j]) {
        flag = true;
        break;
      }
    if (flag == false) {
      k--;
      if (k == 0) {
        for (int j = 1; j <= i - 1; j++) printf("%d", ch[j]);
        printf("\n");
        exit(0);
      }
    }
    flag = false;
    ch[i] = 0;
    memset(cnt, 0, sizeof(cnt));
    if (i == 1) cnt[0] = 1;
    for (int j = 2; j <= n; j++) {
      cnt[j] = cnt[j - 1] + cnt[j - 2];
      if (cnt[j] >= k) {
        flag = true;
        break;
      }
      int id = 0, cut = 0;
      for (int k = 1; k <= len[j - 2]; k++) now[++id] = bak[j - 2][k];
      cut = id;
      for (int k = 1; k <= len[j - 1]; k++) now[++id] = pre[j - 1][k];
      kmp(now, id, ch, i);
      for (int k = cut + 1; k <= min(cut + i - 1, id); k++)
        if (tag[k] == true) cnt[j]++;
    }
    if (cnt[n] >= k || flag == true)
      ch[i] = 0;
    else
      ch[i] = 1, k -= cnt[n];
  }
  for (int i = 1; i <= m; i++) printf("%d", ch[i]);
  printf("\n");
  return 0;
}

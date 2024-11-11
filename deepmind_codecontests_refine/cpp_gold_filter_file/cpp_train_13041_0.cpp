#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 200010, _bas = 19375331;
char s[N];
long long n;
struct node {
  long long len, v;
  unsigned long long Hsh[18];
  node *nxt[18];
  node() {
    for (long long i = (long long)(0); i <= (long long)(17); ++i)
      nxt[i] = NULL, Hsh[i] = 0;
  }
} ans[N];
unsigned long long bas[100];
node Expand(node &p, long long x) {
  node res;
  res.len = p.len + 1;
  res.v = x;
  res.Hsh[0] = x;
  res.nxt[0] = &p;
  for (long long i = (long long)(1); i <= (long long)(17); ++i)
    if (res.nxt[i - 1]->nxt[i - 1] != NULL) {
      res.nxt[i] = res.nxt[i - 1]->nxt[i - 1];
      res.Hsh[i] = res.Hsh[i - 1] + bas[i - 1] * res.nxt[i - 1]->Hsh[i - 1];
    } else
      break;
  return res;
}
bool cmp(node a, node b) {
  for (long long i = (long long)(17); i >= (long long)(0); --i)
    if (a.nxt[i] != NULL && b.nxt[i] != NULL)
      if (a.Hsh[i] == b.Hsh[i]) a = *(a.nxt[i]), b = *(b.nxt[i]);
  return a.v > b.v;
}
void print(node q) {
  write(q.len);
  putchar(' ');
  node *p = &q;
  if (q.len <= 10) {
    for (; p != NULL && p->len; p = p->nxt[0]) printf("%c", char(p->v));
  } else {
    for (long long i = (long long)(1); i <= (long long)(5); ++i)
      printf("%c", char(p->v)), p = p->nxt[0];
    printf("...");
    for (long long i = (long long)(17); i >= (long long)(0); --i) {
      if (p->len - (1 << i) >= 2) p = p->nxt[i];
    }
    for (; p != NULL && p->len; p = p->nxt[0]) printf("%c", char(p->v));
  }
  puts("");
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  bas[0] = _bas;
  for (long long i = (long long)(1); i <= (long long)(17); ++i)
    bas[i] = bas[i - 1] * bas[i - 1];
  for (long long i = (long long)(n); i >= (long long)(1); --i) {
    ans[i] = Expand(ans[i + 1], s[i]);
    if (s[i] == s[i + 1])
      if (cmp(ans[i], ans[i + 2])) ans[i] = ans[i + 2];
  }
  for (long long i = (long long)(1); i <= (long long)(n); ++i) print(ans[i]);
}

#include <bits/stdc++.h>
inline long long Input() {
  long long ret = 0;
  bool isN = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') isN = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return isN ? -ret : ret;
}
inline void Output(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int len = 0, data[20];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
#pragma comment(linker, "/STACK:124000000,124000000")
const long double PI = acos(-1.0);
using namespace std;
struct SHIT {
  int x, p;
} shit[200005];
bool cmp(SHIT a, SHIT b) { return a.x < b.x; }
int q[200005], head, tail;
int main() {
  int n, d, m;
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &shit[i].x, &shit[i].p);
  }
  sort(shit + 1, shit + m + 1, cmp);
  shit[m + 1].x = d;
  shit[0].x = 0;
  int now = n;
  long long ans = 0;
  m++;
  head = tail = 0;
  bool flag = 0;
  for (int i = 1; i <= m; i++) {
    int len = shit[i].x - shit[i - 1].x;
    if (now < len) {
      while (head < tail && now < len) {
        int tmp = min(len - now, n - (now - len + shit[i].x - shit[q[head]].x));
        ans += 1LL * tmp * shit[q[head]].p;
        now += tmp;
        if (n - (now - len + shit[i].x - shit[q[head]].x) == 0) head++;
      }
    }
    now -= len;
    if (now < 0) {
      flag = 1;
      break;
    }
    while (head < tail && shit[i].p <= shit[q[tail - 1]].p) tail--;
    q[tail++] = i;
  }
  if (flag)
    printf("-1\n");
  else
    printf("%I64d\n", ans);
  return 0;
}

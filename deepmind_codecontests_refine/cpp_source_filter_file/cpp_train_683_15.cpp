#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
char s[100010];
struct node {
  int ch[26], v, fail, dep, f;
  void init() {
    memset(ch, 0, sizeof(ch));
    v = fail = dep = f = 0;
  }
} t[100010 * 20];
int sz, n;
void build(char s[]) {
  n = strlen(s);
  int ed = 0, p;
  sz = 0;
  t[0].init();
  t[0].fail = -1;
  for (int i = 0; i < n; i++) {
    int j = s[i] - 'a';
    p = ++sz;
    t[p].init();
    t[p].dep = t[ed].dep + 1;
    while (ed >= 0 && t[ed].ch[j] == 0) t[ed].ch[j] = p, ed = t[ed].fail;
    if (ed < 0) {
      ed = p;
      continue;
    }
    int q = t[ed].ch[j];
    if (t[q].dep == t[ed].dep + 1)
      t[p].fail = q;
    else {
      int r = ++sz;
      t[r] = t[q];
      t[r].dep = t[ed].dep + 1;
      t[r].f = 1;
      t[p].fail = t[q].fail = r;
      while (ed >= 0 && t[ed].ch[j] == q) t[ed].ch[j] = r, ed = t[ed].fail;
    }
    ed = p;
  }
}
int w[100010], id[100010];
long long sqr(int first) { return 1LL * first * first; }
long long run() {
  long long ans = 0;
  for (int i = 0; i < n + 1; i++) w[i] = 0;
  for (int i = 0; i < sz + 1; i++) w[t[i].dep]++;
  for (int i = 1; i < n + 1; i++) w[i] += w[i - 1];
  for (int i = sz + 1 - 1; i >= 0; i--) id[--w[t[i].dep]] = i;
  for (int K = sz + 1 - 1; K >= 1; K--) {
    int i = id[K], j = t[i].fail;
    if (!t[i].f) t[i].v++;
    if (j >= 0) t[j].v += t[i].v;
    ans += sqr(t[i].v) * (t[i].dep - t[j].dep);
  }
  return ans;
}
int main() {
  int T, i = 0, j, k, ca = 0, K, m;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    build(s);
    long long ans = run();
    printf("%I64d\n", ans);
  }
  return 0;
}

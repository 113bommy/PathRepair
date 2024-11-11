#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 4;
const int inf = 0x3f3f3f3f;
const int kid = 2;
int digit[25], p[25];
struct Trie {
  int nxt[maxn][kid], num[maxn];
  int root, L;
  int newnode() {
    for (int i = 0; i < kid; i++) nxt[L][i] = -1;
    num[L] = 0;
    return L++;
  }
  void init() {
    L = 0;
    root = newnode();
  }
  void insert(int x) {
    int len = 20;
    memset(digit, 0, sizeof digit);
    while (x) {
      digit[len--] = x % 2;
      x >>= 1;
    }
    int now = root;
    num[now]++;
    for (int i = 0; i <= 20; i++) {
      int id = digit[i];
      if (nxt[now][id] == -1) nxt[now][id] = newnode();
      now = nxt[now][id];
      num[now]++;
    }
  }
  void cal(int x) {
    int len = 20;
    memset(digit, 0, sizeof digit);
    while (x) {
      digit[len--] = x % 2;
      x >>= 1;
    }
    int now = root;
    int ans = 0;
    for (int i = 0; i <= 20; i++) {
      int id = digit[i];
      if (nxt[now][id] == -1) break;
      if (num[nxt[now][id]] == p[20 - i]) {
        ans += p[20 - i];
        id ^= 1;
        if (nxt[now][id] == -1) break;
      }
      now = nxt[now][id];
    }
    printf("%d\n", ans);
  }
} ac;
int a[maxn];
int main() {
  int n, m, x;
  p[0] = 1;
  for (int i = 1; i <= 20; i++) p[i] = p[i - 1] * 2;
  while (scanf("%d%d", &n, &m) != EOF) {
    ac.init();
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for (int i = 0; i < n; i++) ac.insert(a[i]);
    int now = 0;
    while (m--) {
      scanf("%d", &x);
      now ^= x;
      ac.cal(now);
    }
  }
}

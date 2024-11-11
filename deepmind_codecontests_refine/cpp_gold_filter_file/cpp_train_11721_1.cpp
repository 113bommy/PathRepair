#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
int last[MAXN], nxt[MAXN], a[MAXN], b[MAXN], n, BIT[MAXN], ans[MAXN];
struct Node {
  int pos, nxt;
} node[MAXN * 30];
int head[MAXN], cnt;
void addnode(int i, int j) {
  node[cnt].pos = j;
  node[cnt].nxt = head[i];
  head[i] = cnt++;
}
void add(int i, int val) {
  for (; i <= n; i += i & -i) BIT[i] += val;
}
int hat(int K) {
  int ret = 0;
  for (int j = (17) - 1; j >= (0); j--) {
    int shift = 1 << j;
    if (ret + shift <= n && BIT[ret + shift] <= K) {
      K -= BIT[ret + shift], ret += shift;
    }
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); i++) scanf("%d", a + i);
  memset(last, -1, sizeof last);
  memset(nxt, -1, sizeof nxt);
  memset(head, -1, sizeof head);
  for (int i = (1); i < (n + 1); i++) b[i] = last[a[i]], last[a[i]] = i;
  for (int i = (1); i < (n + 1); i++)
    if (b[i] != -1)
      nxt[b[i]] = i;
    else
      add(i, 1);
  for (int i = (1); i < (n + 1); i++) addnode(1, i);
  for (int i = (1); i < (n + 1); i++) {
    for (int j = head[i]; j != -1; j = node[j].nxt) {
      int p = node[j].pos;
      int res = hat(p);
      ans[p]++;
      if (res + 1 <= n) addnode(res + 1, p);
    }
    add(i, -1);
    if (nxt[i] != -1) add(nxt[i], 1);
  }
  for (int i = (1); i < (n + 1); i++) printf("%d%c", ans[i], " \n"[i == n]);
}

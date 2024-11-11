#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
char str[maxn];
int fa[maxn], cnt[maxn];
bool d[maxn], bd[maxn];
int nFind(int id) {
  if (fa[id] == id)
    return id;
  else
    return fa[id] = nFind(fa[id]);
}
int main() {
  int i, n, nAns = 0, pre, nxt;
  scanf("%s", str);
  n = strlen(str);
  for (i = 0; i < n; i++) bd[i] = (str[i] != str[(i + n - 1) % n]);
  for (i = 0; i < n; i++) {
    pre = (i + n - 1) % n;
    nxt = (i + 1) % n;
    d[i] = (bd[i] && bd[pre] && bd[nxt]);
    if (!bd[i] && bd[pre]) nAns++;
    fa[i] = i;
    cnt[i] = 1;
  }
  for (i = 0; i < n - 1; i++) {
    pre = (i + n - 1) % n;
    if (d[i] && d[pre]) {
      fa[i] = pre;
      cnt[nFind(i)] += cnt[i];
    }
  }
  if (nFind(n - 2) == n - 1) {
    printf("%d\n", (cnt[n - 1] + 1) / 2);
    return 0;
  } else if (d[n - 1] && d[n - 2]) {
    fa[n - 1] = pre;
    cnt[nFind(n - 1)] += cnt[n - 1];
  }
  for (i = 0; i < n; i++) {
    if (d[i] && fa[i] == i) nAns += (cnt[i] + 1) / 2;
  }
  printf("%d\n", nAns);
  return 0;
}

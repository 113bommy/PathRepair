#include <bits/stdc++.h>
using namespace std;
char str[150010];
int l[20], r[20], n;
struct Suffix_Automaton {
  int size, last;
  struct Node {
    int deep, tot, fail;
    int cnt[12], nxt[26];
  } mem[150010 << 3];
  void init() {
    last = size++;
    mem[last].deep = 0;
    mem[last].tot = 1;
    mem[last].fail = -1;
  }
  void extend(int c, int id) {
    int cur, clone, p;
    if (mem[last].nxt[c]) {
      cur = mem[last].nxt[c];
      if (mem[cur].deep == mem[last].deep + 1) {
        mem[cur].cnt[id] = 1;
        last = cur;
        return;
      }
      clone = size++;
      mem[clone] = mem[cur];
      mem[clone].tot = 0;
      mem[clone].deep = mem[last].deep + 1;
      for (int i = 1; i <= n; i++) mem[clone].cnt[i] = 0;
      mem[clone].cnt[id] = 1;
      for (; ~last && mem[last].nxt[c] == cur; last = mem[last].fail) {
        mem[last].nxt[c] = clone;
        mem[clone].tot += mem[last].tot;
        mem[cur].tot -= mem[last].tot;
      }
      mem[cur].fail = clone;
      last = clone;
      return;
    }
    cur = size++;
    mem[cur].deep = mem[last].deep + 1;
    mem[cur].cnt[id] = 1;
    for (; ~last && !mem[last].nxt[c]; last = mem[last].fail) {
      mem[last].nxt[c] = cur;
      mem[cur].tot += mem[last].tot;
    }
    if (last == -1)
      mem[cur].fail = 0;
    else {
      p = mem[last].nxt[c];
      if (mem[p].deep == mem[last].deep + 1)
        mem[cur].fail = p;
      else {
        clone = size++;
        mem[clone] = mem[p];
        mem[clone].deep = mem[last].deep + 1;
        for (int i = 1; i <= n; i++) mem[clone].cnt[i] = 0;
        mem[clone].tot = 0;
        for (; ~last && mem[last].nxt[c] == p; last = mem[last].fail) {
          mem[last].nxt[c] = clone;
          mem[clone].tot += mem[last].tot;
          mem[p].tot -= mem[last].tot;
        }
        mem[cur].fail = mem[p].fail = clone;
      }
    }
    last = cur;
  }
  int cnt[150010], ord[150010 << 3];
  void build(int len) {
    int ans = 0;
    for (int i = 0; i <= len; i++) cnt[i] = 0;
    for (int i = 0; i < size; i++) cnt[mem[i].deep]++;
    for (int i = 1; i <= len; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < size; i++) ord[cnt[mem[i].deep]--] = i;
    for (int i = size; i > 0; i--) {
      int u = ord[i];
      int v = mem[u].fail;
      bool ok = 1;
      if (!mem[u].cnt[0]) ok = 0;
      for (int j = 1; j <= n; j++) {
        if (v >= 0) mem[v].cnt[j] += mem[u].cnt[j];
        if (mem[u].cnt[j] < l[j] || mem[u].cnt[j] > r[j]) ok = 0;
      }
      ans += ok * mem[u].tot;
    }
    cout << ans << endl;
  }
} sam;
int main() {
  sam.init();
  scanf("%s%d", str, &n);
  int len = strlen(str);
  int m = len;
  for (int i = 0; i < len; i++) sam.extend(str[i] - 'a', 0);
  for (int i = 1; i <= n; i++) {
    sam.last = 0;
    scanf("%s%d%d", str, l + i, r + i);
    len = strlen(str);
    for (int j = 0; j < len; j++) sam.extend(str[j] - 'a', i);
    if (m < len) m = len;
  }
  sam.build(m);
  return 0;
}

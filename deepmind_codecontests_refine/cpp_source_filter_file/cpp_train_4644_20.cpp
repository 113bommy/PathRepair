#include <bits/stdc++.h>
using namespace std;
const int MAXNODE = 5000000;
int q, nxt[MAXNODE][2], cnt[MAXNODE], nodeCnt;
int getbit(int mask, int i) { return (mask >> i) & 1; }
void init() { nodeCnt = 0; }
void add(int x) {
  int v = 0;
  for (int i = 6; i >= 0; --i) {
    int c = getbit(x, i);
    if (!nxt[v][c]) nxt[v][c] = ++nodeCnt;
    cnt[v]++;
    v = nxt[v][c];
  }
  cnt[v]++;
}
void del(int x) {
  int v = 0;
  for (int i = 6; i >= 0; --i) {
    int c = getbit(x, i);
    cnt[v]--;
    v = nxt[v][c];
  }
  cnt[v]--;
}
int get(int p, int l) {
  int ret = 0;
  int v = 0;
  for (int i = 6; i >= 0; --i) {
    int bitp = getbit(p, i);
    int bitl = getbit(l, i);
    if (bitl == 1 && nxt[v][bitp]) ret += cnt[nxt[v][bitp]];
    if (nxt[v][bitp ^ bitl])
      v = nxt[v][bitp ^ bitl];
    else
      break;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  cin >> q;
  while (q--) {
    int cmd, p;
    cin >> cmd >> p;
    if (cmd == 1) add(p);
    if (cmd == 2) del(p);
    if (cmd == 3) {
      int l;
      cin >> l;
      cout << get(p, l) << '\n';
    }
  }
  return 0;
}

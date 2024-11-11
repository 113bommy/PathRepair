#include <bits/stdc++.h>
using namespace std;
const int Size = 1024;
const int mod2 = 998244353;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 6e6 + 15;
const int base = 307;
struct node {
  int num;
  int nxt[2];
} t[maxn];
int tot;
void change(int k) {
  int p = 0;
  for (int i = 29; i >= 0; i--) {
    int bit = (k >> i) & 1;
    if (t[p].nxt[bit] == 0) {
      t[p].nxt[bit] = ++tot;
    }
    p = t[p].nxt[bit];
    t[p].num = i;
  }
}
int query(int p) {
  if (t[p].num == 0) return 0;
  if (t[p].nxt[0] && t[p].nxt[1]) {
    return (1 << (t[p].num - 1)) + min(query(t[p].nxt[0]), query(t[p].nxt[1]));
  }
  if (t[p].nxt[0])
    return query(t[p].nxt[0]);
  else
    return query(t[p].nxt[1]);
}
int main() {
  int n;
  scanf("%d", &n);
  t[0].num = 100;
  for (int i = 1; n >= i; i++) {
    int k;
    scanf("%d", &k);
    change(k);
  }
  printf("%d\n", query(0));
  return 0;
}

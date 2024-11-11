#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  int l;
  int r;
  int id;
} ss;
int __an = 0;
ss ans[1000006];
int ak[1000006];
int bit[1000006];
map<int, int> my;
int a[1000006];
int b[1000006];
bool cmp(node p, node q) { return p.r < q.r; }
int sum(int i) {
  int ask = 0;
  while (i > 0) {
    ask ^= bit[i];
    i -= i & (-i);
  }
  return ask;
}
void up(int i, int n, int t) {
  while (i <= t) {
    bit[i] ^= n;
    i += i & (-i);
  }
}
int main(void) {
  int n, m, k;
  int i, j;
  while (scanf("%d", &k) != EOF) {
    my.clear();
    __an++;
    memset(bit, 0, sizeof(bit));
    for (i = 1; i <= k; i++) {
      scanf("%d", &ak[i]);
    }
    memset(a, 0, sizeof(a));
    for (i = 1; i <= k; i++) {
      a[i] = a[i] ^ ak[i];
      a[i] ^= a[i - 1];
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d %d", &ans[i].l, &ans[i].r);
      ans[i].id = i;
    }
    sort(ans, ans + n, cmp);
    for (i = 1; i <= k; i++) {
      if (!my[ak[i]]) {
        my[ak[i]] = i;
      }
      up(i, ak[i], k);
    }
    int ac = 1;
    for (i = 0; i < n; i++) {
      for (j = ac + 1; j <= ans[i].r; j++) {
        int id = my[ak[j]];
        if (id != j) {
          up(id, ak[j], k);
          my[ak[j]] = j;
        }
      }
      ac = ans[i].r;
      b[ans[i].id] = a[ans[i].r] ^ a[ans[i].l - 1];
      b[ans[i].id] ^= sum(ans[i].r) ^ sum(ans[i].l - 1);
    }
    if (__an == 98)
      printf("WOCAO\n");
    else {
      for (i = 0; i < n; i++) {
        printf("%d\n", b[i]);
      }
    }
  }
  return 0;
}

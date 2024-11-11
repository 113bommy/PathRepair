#include <bits/stdc++.h>
using namespace std;
int Root;
struct Btree {
  int ch[30];
  bool vis;
  int siz;
  long long dp[110];
  bool isEnd;
};
Btree tree[110 * 2000];
int nume;
char str[2000];
int len;
void insertNone(int &x) {
  if (!x) {
    x = ++nume;
    tree[x].siz = 0;
    tree[x].isEnd = true;
  }
  tree[x].siz++;
}
void insert(int &x, int now) {
  if (!x) {
    x = ++nume;
    tree[x].siz = 0;
    for (int i = 0; i < 26; i++) tree[x].ch[i] = 0;
    tree[x].isEnd = false;
  }
  tree[x].siz++;
  if (now >= len) {
    insertNone(tree[x].ch[26]);
  } else {
    insert(tree[x].ch[str[now] - 'a'], now + 1);
  }
}
int n, k;
long long DP(int x, int rk) {
  if (tree[x].vis) return tree[x].dp[rk];
  tree[x].vis = true;
  for (int i = 0; i <= k; i++) tree[x].dp[i] = -10000;
  tree[x].dp[0] = 0;
  long long tmp[110];
  if (!tree[x].isEnd) {
    int limi = min(tree[x].siz, k);
    if (tree[x].ch[26]) {
      for (int i = 0; i < 110; i++) tmp[i] = tree[x].dp[i];
      for (int ck = 1; ck <= limi; ck++)
        for (int V = limi; V >= 0; V--) {
          if (V - ck < 0) break;
          tree[x].dp[V] =
              max(tree[x].dp[V], tmp[V - ck] + DP(tree[x].ch[26], ck));
        }
    }
    for (int i = 0; i < 26; i++) {
      if (tree[x].ch[i]) {
        for (int i = 0; i < 110; i++) tmp[i] = tree[x].dp[i];
        for (int ck = 1; ck <= limi; ck++) {
          for (int V = limi; V >= 0; V--) {
            if (V - ck < 0) break;
            tree[x].dp[V] =
                max(tree[x].dp[V],
                    tmp[V - ck] + DP(tree[x].ch[i], ck) +
                        (long long)ck * (long long)(ck - 1) / (long long)2);
          }
        }
      }
    }
  } else {
    for (int i = 0; i <= tree[x].siz; i++) tree[x].dp[i] = 0;
  }
  return tree[x].dp[rk];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    len = strlen(str);
    insert(Root, 0);
  }
  cout << DP(Root, k) << endl;
  return 0;
}

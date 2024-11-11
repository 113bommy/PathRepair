#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int q, x, tot1, tot2, trie1[maxn * 15][26], trie2[maxn * 31][2],
    End1[maxn * 15], End2[maxn * 31], root1[maxn], root2[maxn];
char op[20], s[20];
inline int newnode1(int now) {
  End1[++tot1] = End1[now];
  for (int i = 0; i < 26; ++i) trie1[tot1][i] = trie1[now][i];
  return tot1;
}
inline void insert1(int &root, char s[], int v) {
  int n = strlen(s);
  root = newnode1(root);
  int now = root;
  for (int i = 0; i < n; ++i) {
    int x = s[i] - 'a';
    trie1[now][x] = newnode1(trie1[now][x]);
    now = trie1[now][x];
  }
  End1[now] = v;
}
inline int query1(int now, char s[]) {
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    int x = s[i] - 'a';
    if (!trie1[now][x]) return 0;
    now = trie1[now][x];
  }
  return End1[now];
}
inline int newnode2(int now) {
  End2[++tot2] = End2[now];
  for (int i = 0; i < 2; ++i) trie2[tot2][i] = trie2[now][i];
  return tot2;
}
inline void insert2(int &root, int t, int v) {
  root = newnode2(root);
  int now = root;
  for (int i = 30; i >= 0; --i) {
    int x = (t >> i) & 1;
    trie2[now][x] = newnode2(trie2[now][x]);
    now = trie2[now][x];
    End2[now] += v;
  }
}
inline int query2(int now, int t) {
  int ret = 0;
  for (int i = 30; i >= 0; --i) {
    int x = (t >> i) & 1;
    if (x) ret += End2[trie2[now][0]];
    if (!trie2[now][x]) return ret;
    now = trie2[now][x];
  }
  return ret;
}
int main() {
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%s", op);
    root1[i] = root1[i - 1];
    root2[i] = root2[i - 1];
    if (op[0] == 's') {
      scanf("%s%d", s, &x);
      int v = query1(root1[i], s);
      if (v) insert2(root2[i], v, -1);
      insert2(root2[i], x, 1);
      insert1(root1[i], s, x);
    } else if (op[0] == 'r') {
      scanf("%s", s);
      int v = query1(root1[i], s);
      if (v) {
        insert2(root2[i], v, -1);
        insert1(root1[i], s, 0);
      }
    } else if (op[0] == 'q') {
      scanf("%s", s);
      int v = query1(root1[i], s);
      if (!v)
        puts("-1");
      else
        printf("%d\n", query2(root2[i], v));
      fflush(stdout);
    } else {
      scanf("%d", &x);
      root1[i] = root1[i - x - 1];
      root2[i] = root2[i - x - 1];
    }
  }
  return 0;
}

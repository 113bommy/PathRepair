#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct AC_M {
  int tree[N][26], sum[N], fail[N], cnt, idx[N], tot, g[N];
  queue<int> q;
  AC_M() {
    memset(sum, 0, sizeof(sum));
    memset(g, 0, sizeof(g));
    memset(tree, 0, sizeof(tree));
    memset(fail, 0, sizeof(fail));
    while (!q.empty()) q.pop();
  }
  void insert(char *s, int id) {
    int rt = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      int id = s[i] - 'a';
      if (!tree[rt][id]) tree[rt][id] = ++cnt;
      rt = tree[rt][id];
    }
    sum[rt]++;
    idx[id] = rt;
  }
  void built() {
    for (int i = 0; i < 26; i++) {
      if (tree[0][i] != 0)
        fail[tree[0][i]] = 0, q.push(tree[0][i]), sum[tree[0][i]] += sum[0];
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i < 26; i++)
        if (tree[now][i])
          fail[tree[now][i]] = tree[fail[now]][i], q.push(tree[now][i]),
          sum[tree[now][i]] += sum[fail[tree[now][i]]];
        else
          tree[now][i] = tree[fail[now]][i];
    }
  }
  void query(char *s) {
    int len = strlen(s), now = 0;
    for (int i = 0; i < len; i++) {
      int id = s[i] - 'a';
      now = tree[now][id];
      g[i] = sum[now];
    }
  }
} ac1, ac2;
char t[N], s[N];
int n;
int main() {
  scanf("%s", t);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    ac1.insert(s, i);
    reverse(s, s + len);
    ac2.insert(s, i);
  }
  ac1.built();
  ac2.built();
  ac1.query(t);
  int len = strlen(t);
  reverse(t, t + len);
  ac2.query(t);
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    ans += ac1.g[i] * ac2.g[len - i - 2];
  }
  cout << ans << endl;
}

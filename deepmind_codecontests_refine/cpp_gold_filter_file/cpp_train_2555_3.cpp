#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int maxn = 1e5 + 105;
struct Trie {
  int next[500010][26], fail[500010], end[500010];
  int root, L;
  int newnode() {
    for (int i = 0; i < 26; i++) next[L][i] = -1;
    end[L++] = 0;
    return L - 1;
  }
  void init() {
    L = 0;
    root = newnode();
  }
  void insert(char buf[], int val) {
    int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++) {
      if (next[now][buf[i] - 'a'] == -1) next[now][buf[i] - 'a'] = newnode();
      now = next[now][buf[i] - 'a'];
    }
    end[now] += val;
  }
  void build() {
    queue<int> Q;
    fail[root] = root;
    for (int i = 0; i < 26; i++)
      if (next[root][i] == -1)
        next[root][i] = root;
      else {
        fail[next[root][i]] = root;
        Q.push(next[root][i]);
      }
    while (!Q.empty()) {
      int now = Q.front();
      end[now] += end[fail[now]];
      Q.pop();
      for (int i = 0; i < 26; i++)
        if (next[now][i] == -1)
          next[now][i] = next[fail[now]][i];
        else {
          fail[next[now][i]] = next[fail[now]][i];
          Q.push(next[now][i]);
        }
    }
  }
  int query(char buf[]) {
    int len = strlen(buf);
    int now = root;
    int res = 0;
    for (int i = 0; i < len; i++) {
      now = next[now][buf[i] - 'a'];
      int temp = now;
      while (temp != root) {
        res += end[temp];
        end[temp] = 0;
        temp = fail[temp];
      }
    }
    return res;
  }
} AC;
struct mat {
  long long val[210][210];
  int si;
  mat friend operator*(mat a, mat b) {
    mat res;
    res.si = a.si;
    memset(res.val, -1, sizeof(res.val));
    for (int k = 0; k <= a.si; k++)
      for (int i = 0; i <= a.si; i++)
        for (int j = 0; j <= a.si; j++)
          if (a.val[i][k] != -1 && b.val[k][j] != -1)
            res.val[i][j] = max(res.val[i][j], a.val[i][k] + b.val[k][j]);
    return res;
  }
};
mat A;
int n;
long long L;
int a[300];
char W[300][300];
int main() {
  scanf("%d %I64d", &n, &L);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  AC.init();
  for (int i = (1); i <= (n); ++i) {
    scanf("%s", W[i]);
    AC.insert(W[i], a[i]);
  }
  AC.build();
  A.si = AC.L - 1;
  memset(A.val, -1, sizeof(A.val));
  for (int i = 0; i < AC.L; i++)
    for (int j = 0; j < 26; j++)
      A.val[i][AC.next[i][j]] = AC.end[AC.next[i][j]];
  mat res;
  res.si = A.si;
  memset(res.val, -1, sizeof(res.val));
  res.val[0][0] = 0;
  while (L) {
    if (L & 1) res = res * A;
    A = A * A;
    L >>= 1;
  }
  long long ans = 0;
  for (int i = 0; i < AC.L; i++) ans = max(ans, res.val[0][i]);
  printf("%I64d", ans);
  return 0;
}

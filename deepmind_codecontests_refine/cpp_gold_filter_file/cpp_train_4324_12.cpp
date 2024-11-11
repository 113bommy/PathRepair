#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node {
  int v, next, num;
} e[maxn << 1];
int n;
int cnt, head[maxn];
inline void add(int x, int y, int num) {
  e[++cnt].v = y;
  e[cnt].next = head[x];
  head[x] = cnt;
  e[cnt].num = num;
}
int du[maxn], ans;
vector<int> pth[maxn];
void dfs(int x, int fa, int last) {
  int tot = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int to = e[i].v;
    if (to == fa) continue;
    if (tot == last) tot++;
    pth[tot].push_back(e[i].num);
    dfs(to, x, tot++);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y, i), add(y, x, i);
    du[x]++, du[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (du[i] > ans) ans = du[i];
  }
  dfs(1, 0, 0);
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) {
    int sz = pth[i].size();
    cout << sz << " ";
    for (int j = 0; j < sz; j++) cout << pth[i][j] << " ";
    cout << endl;
  }
}

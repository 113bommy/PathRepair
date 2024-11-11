#include <bits/stdc++.h>
using namespace std;
struct node {
  int son[26];
  bool mark;
  priority_queue<int> q;
} t[100005];
int cnt = 1;
int n, ans = 0;
char a[100005];
void insert(char a[]) {
  int len = strlen(a);
  int now = 1;
  for (int i = 0; i < len; i++) {
    if (!t[now].son[a[i] - 'a']) t[now].son[a[i] - 'a'] = ++cnt;
    now = t[now].son[a[i] - 'a'];
  }
  t[now].mark = 1;
  t[now].q.push(len);
  ans += len;
}
void dfs(int now, int dep, int num) {
  for (int i = 0; i < 25; i++)
    if (t[now].son[i]) {
      int x = t[now].son[i];
      dfs(x, dep + 1, i);
      while (!t[x].q.empty()) {
        t[now].q.push(t[x].q.top());
        t[x].q.pop();
      }
    }
  if (!t[now].mark && !t[now].q.empty() && now != 1) {
    ans -= t[now].q.top() - dep;
    t[now].q.pop();
    t[now].q.push(dep);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%s", &a);
    insert(a);
  }
  dfs(1, 0, -1);
  cout << ans << endl;
  return 0;
}

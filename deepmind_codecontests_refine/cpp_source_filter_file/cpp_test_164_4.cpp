#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
struct node {
  int left;
  int right;
};
struct node t[N + 5];
int tot, id[N + 5], depth[N + 5];
char a[N + 5];
bool col[N + 5];
char str[N + 5], dif[N + 5];
void dfs(int place, int father) {
  if (!place) return;
  depth[place] = depth[father] + 1;
  dfs(t[place].left, place);
  str[++tot] = a[place];
  id[place] = tot;
  dfs(t[place].right, place);
}
void print(int place) {
  if (!place) return;
  print(t[place].left);
  printf("%c", a[place]);
  if (col[place]) printf("%c", a[place]);
  print(t[place].right);
}
int k;
bool add(int place, int top) {
  bool ans = 0;
  if (t[place].left && k > 1) ans = add(t[place].left, top);
  if (ans)
    col[place] = 1;
  else if (a[place] < dif[id[place]] && k >= depth[place] - depth[top]) {
    k -= depth[place] - depth[top];
    ans = 1;
    col[place] = 1;
  }
  if (!ans) return 0;
  if (t[place].right && k > 1) add(t[place].right, place);
  return 1;
}
int main() {
  int n;
  scanf("%d%d", &n, &k);
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].left, &t[i].right);
  dfs(1, 1);
  dif[n] = str[n];
  for (int i = n - 1; i >= 1; i--) {
    if (str[i] == str[i + 1])
      dif[i] = dif[i + 1];
    else
      dif[i] = str[i + 1];
  }
  add(1, 0);
  print(1);
  return 0;
}

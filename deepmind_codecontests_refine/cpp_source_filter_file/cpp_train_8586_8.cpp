#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector<int> v[MAX], worker;
queue<int> q;
int a[MAX], vis[MAX];
int main() {
  int n, x;
  char s[MAX];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j)
      if (s[i] == '1') v[i].push_back(j);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 0) q.push(i);
  }
  for (; !q.empty();) {
    x = q.front();
    q.pop();
    worker.push_back(x);
    for (int i = 0; i < v[x].size(); ++i) {
      int y = v[x][i];
      a[y]--;
      if (a[y] == 0) q.push(y);
    }
  }
  printf("%d\n", worker.size());
  for (int i = 0; i < worker.size(); ++i) printf("%d ", worker[i]);
  printf("\n");
  return 0;
}

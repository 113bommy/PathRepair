#include <bits/stdc++.h>
using namespace std;
int n, a, b, route[300005], cnt = 0;
bool p[300005], flag = 0;
vector<int> V[300005];
typedef struct aa {
  int id, v;
  friend bool operator<(aa a, aa b) { return a.v < b.v; }
} NUM;
NUM num[100005];
int binary_search(int l, int r, int a) {
  int m = (l + r) / 2;
  if (r - l <= 1) {
    if (num[l].v == a) return l;
    if (num[r].v == a) return r;
    return -1;
  }
  if (num[m].v == a) return m;
  if (num[m].v > a) return binary_search(l, m - 1, a);
  return binary_search(m + 1, r, a);
}
void input() {
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &num[i].v);
    num[i].id = i;
  }
  sort(num, num + n);
  for (int i = 0; i <= n - 1; i++) {
    int a1, b1;
    a1 = binary_search(0, n - 1, a - num[i].v);
    if (a1 == -1) p[num[i].id * 2 + 1] = 1;
    b1 = binary_search(0, n - 1, b - num[i].v);
    if (a1 == -1 && b1 == -1) flag = 1;
    if (b1 == -1) p[num[i].id * 2] = 1;
    int x = a1;
    while (x >= 0 && num[x].v == a - num[i].v) {
      V[num[i].id * 2].push_back(num[x].id * 2);
      V[num[x].id * 2 + 1].push_back(num[i].id * 2 + 1);
      x--;
    }
    x = a1 + 1;
    while (x < n && num[x].v == a - num[i].v) {
      V[num[i].id * 2].push_back(num[x].id * 2);
      V[num[x].id * 2 + 1].push_back(num[i].id * 2 + 1);
      x++;
    }
    int y = b1;
    if (y >= 0 && num[y].v == b - num[i].v) {
      V[num[y].id * 2].push_back(num[i].id * 2);
      V[num[i].id * 2 + 1].push_back(num[y].id * 2 + 1);
      y--;
    }
    y = b1 + 1;
    if (y < n && num[y].v == b - num[i].v) {
      V[num[y].id * 2].push_back(num[i].id * 2);
      V[num[i].id * 2 + 1].push_back(num[y].id * 2 + 1);
      y++;
    }
  }
  return;
}
bool dfs(int u) {
  if (p[u]) return 1;
  if (p[u ^ 1]) return 0;
  p[u] = 1;
  route[cnt++] = u;
  for (int i = 0; i < V[u].size(); i++) {
    if (!dfs(V[u][i])) return 0;
  }
  return 1;
}
void reset_mark() {
  cnt--;
  while (cnt >= 0) {
    p[route[cnt--]] = false;
  }
  cnt = 0;
  return;
}
bool Two_Sat() {
  for (int i = 0; i <= n - 1; i++) {
    cnt = 0;
    if (p[2 * i] || p[2 * i + 1]) continue;
    if (!dfs(2 * i)) {
      reset_mark();
      if (!dfs(2 * i + 1)) return false;
    }
  }
  return true;
}
int main() {
  while (scanf("%d%d%d", &n, &a, &b) != EOF) {
    input();
    if (!Two_Sat() || flag)
      printf("NO\n");
    else {
      printf("YES\n");
      for (int i = 0; i <= n - 1; i++) {
        if (i) printf(" ");
        if (p[2 * i]) {
          printf("0");
        } else
          printf("1");
      }
      printf("\n");
    }
  }
  return 0;
}

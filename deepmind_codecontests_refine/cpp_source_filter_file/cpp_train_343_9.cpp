#include <bits/stdc++.h>
using namespace std;
double minn = 1e9 + 5, ans;
int n, k, tot;
bool vis[1005];
struct Node {
  int id;
  double var;
  Node(int _id = 0, double _var = 0) {
    id = _id;
    var = _var;
  }
  friend bool operator<(Node a, Node b) { return a.var < b.var; }
} a[1005];
queue<int> Q[1005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    double x;
    int t;
    scanf("%lf%d", &x, &t);
    if (t == 1) {
      a[++tot] = Node(i, x);
    } else {
      ans += x;
      minn = min(minn, x);
    }
  }
  sort(a + 1, a + tot + 1);
  if (k - 1 < tot) {
    for (int i = 1; i <= k - 1; i++) {
      ans += a[tot - i + 1].var * 0.5;
      vis[a[tot - i + 1].id] = 1;
      Q[i].push(a[tot - i + 1].id);
    }
    for (int i = k; i <= tot; i++) {
      minn = min(minn, a[tot - i + 1].var);
      ans += a[tot - i + 1].var;
      vis[a[tot - i + 1].id] = 1;
      Q[k].push(a[tot - i + 1].id);
    }
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) Q[k].push(i);
    }
    ans -= minn * 0.5;
    printf("%.1lf\n", ans);
    for (int i = 1; i <= k; i++) {
      printf("%d", Q[i].size());
      while (!Q[i].empty()) {
        printf(" %d", Q[i].front());
        Q[i].pop();
      }
      printf("\n");
    }
  } else {
    for (int i = 1; i <= tot; i++) {
      ans += 0.5 * a[i].var;
      vis[a[i].id] = 1;
      Q[i].push(a[i].id);
    }
    printf("%.1lf\n", ans);
    if (k - 1 == tot) {
      for (int i = 1; i <= tot; i++) {
        if (!vis[i]) Q[k].push(i);
      }
      for (int i = 1; i <= k; i++) {
        printf("%d", Q[i].size());
        while (!Q[i].empty()) {
          printf(" %d", Q[i].front());
          Q[i].pop();
        }
        printf("\n");
      }
    } else {
      int now = tot;
      while (now != k - 1) {
        for (int i = 1; i <= n; i++) {
          if (!vis[i]) Q[++now].push(i);
          vis[i] = 1;
          if (now == k - 1) break;
        }
      }
      for (int i = 1; i <= n; i++) {
        if (!vis[i]) Q[k].push(i);
      }
      for (int i = 1; i <= k; i++) {
        printf("%d", Q[i].size());
        while (!Q[i].empty()) {
          printf(" %d", Q[i].front());
          Q[i].pop();
        }
        printf("\n");
      }
    }
  }
  return 0;
}

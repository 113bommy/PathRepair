#include <bits/stdc++.h>
struct node {
  int next[19] = {};
};
int n, q;
int a[305];
node nodes[305];
bool isReachable(int curr, int end) {
  for (int i = 0; i < 19; i++) {
    if ((a[end] & (1 << i)) && nodes[curr].next[i] &&
        nodes[curr].next[i] <= end) {
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  std::vector<int> ns[19][19];
  int has[19], wants[19];
  for (int i = 1; i <= n; i++) {
    int hasCount = 0, wantsCount = 0;
    for (int bit = 0; bit < 19; bit++) {
      if ((a[i] & (1 << bit))) {
        has[hasCount++] = bit;
        nodes[i].next[bit] = i;
      } else {
        wants[wantsCount++] = bit;
      }
    }
    for (int i2 = 0; i2 < hasCount; i2++) {
      for (int i3 = 0; i3 < hasCount; i3++) {
        for (auto &v : ns[has[i2]][has[i3]]) {
          if (!nodes[v].next[has[i3]]) {
            nodes[v].next[has[i3]] = i;
            for (int bit = 0; bit < 19; bit++) {
              if (!nodes[v].next[i]) {
                ns[has[i3]][bit].push_back(v);
              }
            }
          }
        }
        ns[has[i2]][has[i3]].clear();
      }
    }
    for (int i2 = 0; i2 < hasCount; i2++) {
      for (int i3 = 0; i3 < wantsCount; i3++) {
        ns[has[i2]][wants[i3]].push_back(i);
      }
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%s\n", isReachable(l, r) ? "Shi" : "Fou");
  }
  return 0;
}

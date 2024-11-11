#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int pos, len;
  friend bool operator<(node a, node b) { return a.len > b.len; }
} f[100005];
vector<int> po;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x = i * 2 - 1;
    f[i].pos = x;
    scanf("%d", &f[i].len);
  }
  sort(f + 1, f + n + 1);
  int jl = 0;
  for (int i = 1; i <= n; i++) {
    po.push_back(f[i].pos);
    if (i == 1)
      jl = f[i].pos;
    else {
      printf("%d %d\n", jl, f[i].pos);
      jl = f[i].pos;
    }
  }
  for (int i = 1; i <= n; i++) {
    int now = f[i].pos + 1;
    int len = f[i].len;
    if (len - 1 + i <= po.size()) {
      printf("%d %d\n", now, po[i + len - 2]);
      if (len - 1 + i == po.size()) po.push_back(now);
    }
  }
  return 0;
}

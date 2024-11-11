#include <bits/stdc++.h>
using namespace std;
struct node {
  int id, val;
} p[100005];
bool cmp(node x, node y) { return x.val < y.val; }
int ans[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    p[i].id = i;
    scanf("%d", &p[i].val);
  }
  sort(p + 1, p + n + 1, cmp);
  int last = 1;
  long long int sum = 0;
  int cnt = 0;
  while (1) {
    int t = last + (n - p[last].val) - 1;
    if (p[t].val == p[last].val) {
      cnt++;
      for (int j = last; j <= t; j++) {
        ans[p[j].id] = cnt;
      }
      sum += (n - p[last].val);
      last = t + 1;
      if (t == n) break;
    } else {
      printf("Impossible\n");
      return 0;
    }
  }
  if (sum != n) {
    printf("Impossible\n");
  } else {
    printf("possible\n");
    for (int i = 1; i <= n; i++) {
      printf("%d ", ans[i]);
    }
  }
  return 0;
}

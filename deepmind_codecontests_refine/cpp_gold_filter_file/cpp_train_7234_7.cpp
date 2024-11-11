#include <bits/stdc++.h>
using namespace std;
struct Node {
  int h;
  int no;
};
int n;
int num[1005005], ans[1005005];
Node node[1005005];
bool cmp(Node a, Node b) {
  if (a.h != b.h) {
    return a.h < b.h;
  }
  return a.no < b.no;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    node[i].h = num[i];
    node[i].no = i;
  }
  sort(node + 1, node + 1 + n, cmp);
  for (int i = 1; i <= (n + 1) / 2; i++) {
    ans[i] = i < num[i] ? i : num[i];
    ans[n + 1 - i] = i < num[n + 1 - i] ? i : num[n + 1 - i];
  }
  for (int i = 1; i <= n; i++) {
    if (node[i].h > (n + 1) / 2) break;
    int days = node[i].h + 1;
    for (int j = node[i].no + 1; j <= n; j++) {
      if (days >= ans[j]) break;
      ans[j] = days;
      days++;
    }
    days = node[i].h + 1;
    for (int j = node[i].no - 1; j > 0; j--) {
      if (days >= ans[j]) break;
      ans[j] = days;
      days++;
    }
  }
  int maxs = 0;
  for (int i = 1; i <= n; i++) maxs = maxs > ans[i] ? maxs : ans[i];
  printf("%d\n", maxs);
  return 0;
}

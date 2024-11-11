#include <bits/stdc++.h>
using namespace std;
char str[100005];
int ans[100005];
int lowbit(int x) { return (x & -x); }
struct Node {
  int x;
  int low;
} node[100005];
bool cmp(Node a, Node b) { return a.low > b.low; }
int main() {
  int sum, k;
  while (~scanf("%d%d", &sum, &k)) {
    int cnt = 0;
    int i, j;
    for (i = 1; i <= k; i++) {
      node[i].x = i;
      node[i].low = lowbit(i);
    }
    sort(node + 1, node + k + 1, cmp);
    for (i = 1; i <= k; i++) {
      if (sum >= node[i].low) {
        sum -= node[i].low;
        ans[cnt++] = node[i].x;
      }
    }
    if (sum)
      cout << "-1" << endl;
    else {
      cout << cnt << endl << ans[0];
      for (i = 1; i < cnt; i++) cout << " " << ans[i];
      cout << endl;
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int dep[N];
int pre[N], tem[N];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int all = 0;
    memset(dep, 0, sizeof(dep));
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", &pre[i], &tem[i]);
      all += tem[i];
      dep[pre[i]]++;
    }
    if (all % 3) {
      printf("-1\n");
      continue;
    }
    queue<int> Q;
    for (int i = 1; i <= n; ++i)
      if (dep[i] == 0) Q.push(i);
    int a1 = 0, a2 = 0;
    while (!Q.empty()) {
      int pos = Q.front();
      Q.pop();
      dep[pre[pos]]--;
      int wei = tem[pos];
      if (wei == all / 3) {
        if (!a1 && pre[pos])
          a1 = pos;
        else if (!a2 && pre[pos])
          a2 = pos;
        tem[pos] = 0;
      }
      tem[pre[pos]] += tem[pos];
      if (dep[pre[pos]] == 0 && pre[pos] != 0) Q.push(pre[pos]);
    }
    if (a1 && a2)
      printf("%d %d\n", a1, a2);
    else
      printf("-1\n");
  }
  return 0;
}

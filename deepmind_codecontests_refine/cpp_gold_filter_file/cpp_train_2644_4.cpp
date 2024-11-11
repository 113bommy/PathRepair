#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 5;
const int N = 1e6 + 2;
int in[maxn][2];
int temp[N];
vector<int> ans;
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    ans.clear();
    memset(in, 0, sizeof(in));
    memset(temp, 0, sizeof(temp));
    for (i = 1; i <= n; i++) {
      scanf("%d%d", &in[i][0], &in[i][1]);
      temp[in[i][0]]++;
      temp[in[i][1]]--;
    }
    int a = -1, b = -1;
    int maxn = 0;
    for (i = 1; i <= N; i++) {
      maxn += temp[i];
      if (maxn > 1) {
        if (maxn >= 3) {
          printf("0\n");
          return 0;
        }
        if (a == -1) a = i;
        b = i;
      }
    }
    for (i = 1; i <= n; i++) {
      if (a == -1 || in[i][0] <= a && b <= in[i][1] - 1) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    if (ans.size()) {
      printf("%d", ans[0]);
      for (i = 1; i < ans.size(); i++) printf(" %d", ans[i]);
      printf("\n");
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> edges[N];
vector<int> state(N, 0);
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i += 1) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
  }
  for (int i = 1; i <= n; i += 1) {
    if (state[i] == 0) {
      state[i] = 1;
      for (int next : edges[i]) {
        if (state[next] == 0) state[next] = -1;
      }
    }
  }
  for (int i = n; i > 0; i -= 1) {
    if (state[i] == 1) {
      for (int next : edges[i]) state[next] = -1;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i += 1) {
    if (state[i] == 1) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int x : ans) printf("%d ", x);
  printf("\n");
}

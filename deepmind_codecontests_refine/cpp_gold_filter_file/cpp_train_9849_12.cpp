#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool in_range(int x, int a, int b) {
  return a <= x && x < b;
}
int N, K;
void solve(int exitNode, int curNode, int cnt) {
  int node = K;
  for (int i = 0, _n = cnt; i < _n; i++) {
    printf("%d %d\n", node + 1, curNode + i + 1);
    node = curNode + i;
  }
  printf("%d %d\n", node + 1, exitNode + 1);
}
int main() {
  scanf("%d %d", &N, &K);
  int M = N - K - 1;
  if (M % K > 1) {
    printf("%d\n", (M / K + 1 + 1) * 2);
  } else if (M % K == 1) {
    printf("%d\n", (M / K + 1 + 1) + (M / K + 1));
  } else {
    printf("%d\n", (M / K + 1) * 2);
  }
  int cur = K + 1;
  for (int i = 0, _n = M % K; i < _n; i++) {
    solve(i, cur, M / K + 1);
    cur += M / K + 1;
  }
  for (int i = 0, _n = K - (M % K); i < _n; i++) {
    solve(M % K + i, cur, M / K);
    cur += M / K;
  }
}

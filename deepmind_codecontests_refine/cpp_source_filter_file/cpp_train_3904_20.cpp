#include <bits/stdc++.h>
using namespace std;
int n, m, K, i, j, k, u, v;
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (; K; --K) {
    scanf("%d%d", &u, &v);
    if (u <= 3 || v <= 3 || n - u <= 2 && m - v <= 2) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}

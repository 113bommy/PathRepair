#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 20;
void solve() {
  int k;
  scanf("%d", &k);
  printf("%d %d\n", 2, 3);
  printf("%d %d %d\n", INF + k, k, 0);
  printf("%d %d %d\n", INF, INF + k, k);
}
int main() {
  solve();
  return 0;
}

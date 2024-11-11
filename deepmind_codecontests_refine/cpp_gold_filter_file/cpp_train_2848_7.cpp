#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  vector<int> V(100005);
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &V[i]);
  bool valid = true;
  for (int i = k + 1; i <= n; i++) valid &= V[i] == V[k];
  if (valid) {
    int i = k;
    while (V[i] == V[k]) i--;
    printf("%d\n", i);
  } else {
    puts("-1");
  }
  return 0;
}

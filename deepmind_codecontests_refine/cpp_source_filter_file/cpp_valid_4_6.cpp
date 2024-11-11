#include <bits/stdc++.h>
int t, P;
std::vector<int> prime;
bool vis[100005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &P);
    printf("%d %d\n", P - 1, 2);
  }
  return 0;
}

#include <bits/stdc++.h>
int t, P;
std::vector<int> prime;
bool vis[100005];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &P);
    printf("%d %d\n", 2, P - 1);
  }
  return 0;
}

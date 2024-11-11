#include <bits/stdc++.h>
using namespace std;
bool ok[1010];
int deg[1010], a[1010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a[i]);
    ok[a[i]] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!ok[a[i]]) deg[a[i]]++;
  for (int i = 1; i <= n; i++)
    if (ok[i] && deg[i] < 3) {
      puts("No");
      return 0;
    }
  puts("Yes");
  return 0;
}

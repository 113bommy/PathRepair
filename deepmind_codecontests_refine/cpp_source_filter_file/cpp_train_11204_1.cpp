#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 5;
bool ha[MAX_N], p[MAX_N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  printf("1");
  int maxn = n, ans = 1;
  for (int i = 1; i <= n; i++) {
    ha[p[i]] = 1;
    ans++;
    while (ha[maxn]) {
      maxn--;
      ans--;
    }
    printf(" %d", ans);
  }
  printf("\n");
  return 0;
}

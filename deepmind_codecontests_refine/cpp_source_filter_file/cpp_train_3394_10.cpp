#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[100010];
int num[1000010];
int vis[1000010];
int ans[1000010];
int main() {
  for (int i = 0; i <= 1000000; i++) ans[i] = 1;
  int n, A;
  scanf("%d%d", &n, &A);
  ans[A] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    int k = a[i];
    vis[k] = 1;
    num[k]++;
    if (k != A && num[k] <= num[A]) ans[k] = 0;
  }
  for (int i = 0; i < n; i++)
    if (ans[a[i]] && num[a[i]] > num[A]) {
      printf("%d", a[i]);
      return 0;
    }
  printf("-1");
  return 0;
}

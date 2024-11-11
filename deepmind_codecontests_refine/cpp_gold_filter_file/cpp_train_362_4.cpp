#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int N, M, arr[maxn], vis[maxn];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", arr + i), vis[arr[i]]++;
  long long ans = 0;
  for (int i = 1; i <= M; i++) {
    ans += vis[i - 1] * vis[i];
    vis[i] += vis[i - 1];
  }
  printf("%lld\n", ans);
}

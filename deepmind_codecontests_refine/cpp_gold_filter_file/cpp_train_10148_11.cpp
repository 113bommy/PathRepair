#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int a[100005];
int p[100005];
void init() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &a[i]);
    p[a[i]] = i;
  }
}
long long ans = 0;
void solve() {
  int x;
  for (int i = 1; i <= M; ++i) {
    scanf("%d", &x);
    ans += (p[x] - 1) / K + 1;
    if (p[x] > 1) {
      p[a[p[x] - 1]] += 1;
      swap(a[p[x]], a[p[x] - 1]);
      p[x] -= 1;
    }
  }
  cout << ans << endl;
}
int main() {
  init();
  solve();
  return 0;
}

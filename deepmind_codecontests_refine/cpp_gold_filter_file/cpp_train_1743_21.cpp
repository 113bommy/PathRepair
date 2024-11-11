#include <bits/stdc++.h>
using namespace std;
int ty[4] = {1, 5, 10, 50};
int a[15];
set<int> s;
int cnt = 0;
int n;
void dfs(int x) {
  if (x == n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    s.insert(sum);
    return;
  }
  for (int i = 0; i <= 3; i++) {
    a[x + 1] = ty[i];
    dfs(x + 1);
  }
}
int fuck[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  cin >> n;
  if (n <= 11)
    printf("%d", fuck[n]);
  else {
    n -= 10;
    int a1 = 292;
    int d = 49;
    long long an = a1 + 1ll * (n - 1) * d;
    printf("%I64d\n", an);
  }
}

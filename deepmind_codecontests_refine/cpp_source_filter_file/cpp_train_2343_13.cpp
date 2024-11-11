#include <bits/stdc++.h>
using namespace std;
int w[1001000];
int main() {
  int x, n, ans;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &x), w[x]++;
  for (int i = 0; i <= 1001000; i++) {
    ans += w[i] % 2;
    w[i + 1] += w[i] / 2;
  }
  cout << ans;
}

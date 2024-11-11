#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p[100001];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &p[i]);
  }
  int ans = 0, sum = 0, now = 1;
  while (now <= m) {
    long long r = ((p[now] - sum - 1) / k + 1) * k + sum;
    while (now <= m && p[now] <= r) {
      sum++;
      now++;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}

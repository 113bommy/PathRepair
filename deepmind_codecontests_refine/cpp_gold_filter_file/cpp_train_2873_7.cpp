#include <bits/stdc++.h>
using namespace std;
int sum(int x, int y) {
  return ((x + y) % 1000000007 + 1000000007) % 1000000007;
}
int mul(long long x, long long y) { return (x * y) % 1000000007; }
int ar[300001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &ar[i]);
  }
  sort(ar + 1, ar + 1 + n);
  int num_groups = 0;
  int s = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = sum(ans, sum(s, mul(num_groups, ar[i])));
    s = mul(s, 2);
    num_groups = sum(1, mul(num_groups, 2));
    s = sum(s, -ar[i]);
  }
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int cnt[300005];
int num[(1 << 20) + 5][2];
int main() {
  int a;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    cnt[i] = cnt[i - 1] ^ a;
  }
  long long ans = 0;
  num[0][0];
  for (int i = 1; i <= n; i++) {
    ans += num[cnt[i]][i & 1];
    num[cnt[i]][i & 1]++;
  }
  cout << ans;
  return 0;
}

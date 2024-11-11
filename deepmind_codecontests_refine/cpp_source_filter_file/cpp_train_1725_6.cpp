#include <bits/stdc++.h>
using namespace std;
int a[200005];
int cnt[200005];
int sum[200005];
int cnt0;
void solve() {
  int n, s;
  int res = 0;
  cin >> n >> s;
  --s;
  for (int i = 0; i < (n); ++i) {
    scanf("%d", a + i);
  }
  if (a[s] != 0) a[s] = 0, ++res;
  if (n == 1) {
    printf("%d\n", res);
    return;
  }
  sort(a, a + n);
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0, sizeof(sum));
  cnt0 = 0;
  for (int i = 0; i < (n); ++i) {
    cnt[a[i]] = 1;
    sum[a[i]]++;
    if (a[i] == 0) ++cnt0;
  }
  for (int i = 1; i <= (n); ++i) a[i] += a[i - 1];
  for (int i = 1; i <= (n); ++i) sum[i] += sum[i - 1];
  int mx = n;
  for (int i = 1; i <= (n); ++i) {
    mx = min(mx, max(i + 1 - cnt[i], n - sum[i] + cnt0 - 1));
  }
  res += mx;
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}

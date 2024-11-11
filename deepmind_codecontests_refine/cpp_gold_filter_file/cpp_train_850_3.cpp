#include <bits/stdc++.h>
using namespace std;
long long N, ans, a[300005];
long long pre[300005], suf[300005];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  ans = (N * (N - 1)) / 2;
  for (long long i = 1; i <= N; i++) {
    char x;
    cin >> x;
    a[i] = x - 'A';
  }
  pre[1] = 1;
  for (long long i = 2; i <= N; i++) {
    if (a[i] == a[i - 1])
      pre[i] = pre[i - 1] + 1;
    else
      pre[i] = 1;
  }
  suf[N] = 1;
  for (long long i = N - 1; i >= 1; i--) {
    if (a[i] == a[i + 1])
      suf[i] = suf[i + 1] + 1;
    else
      suf[i] = 1;
  }
  a[0] = a[1];
  a[N + 1] = a[N];
  for (long long i = 1; i <= N; i++) {
    long long tmp = 1;
    if (a[i] == a[i - 1] && a[i] == a[i + 1]) continue;
    if (a[i] != a[i - 1] && a[i] != a[i + 1])
      tmp = pre[i - 1] + suf[i + 1];
    else if (a[i] != a[i - 1])
      tmp = pre[i - 1];
    else if (a[i] != a[i + 1])
      tmp = suf[i + 1];
    ans -= tmp;
  }
  for (long long i = 1; i < N; i++)
    if (a[i] != a[i + 1]) ans++;
  cout << ans << "\n";
  return 0;
}

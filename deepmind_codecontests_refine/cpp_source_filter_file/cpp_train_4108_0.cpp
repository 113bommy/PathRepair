#include <bits/stdc++.h>
using namespace std;
int cnt[100001];
long long f[100001];
int a;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    cnt[a]++;
  }
  if (cnt[a] == n) {
    cout << n * a;
    return 0;
  }
  f[1] = cnt[1];
  f[0] = 0;
  for (int i = 2; i <= n; ++i) {
    f[i] = max(f[i - 1], f[i - 2] + (cnt[i] * 1ll * i));
  }
  cout << f[n];
}

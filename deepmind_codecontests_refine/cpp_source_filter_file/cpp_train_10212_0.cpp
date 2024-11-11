#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a[maxn];
int cnt[2 * maxn];
long long calc(int m) {
  for (int i = 0; i <= 2 * n; i++) cnt[i] = 0;
  int sum = n;
  long long add = 0;
  cnt[sum] = 1;
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < m) {
      sum -= 1;
      add -= cnt[sum];
    } else {
      add += cnt[sum];
      sum += 1;
    }
    ret += add;
    cnt[sum]++;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << calc(m) - calc(m + 1);
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int maxa = 1e6 + 5;
int N, a[maxn], K;
int D[maxa], E[maxa];
int cnt[maxa];
bool check(int res) {
  if (E[res] > K * (K + 1) / 2) return false;
  int ret = 0;
  for (int i = 1; i <= N; ++i) {
    if (cnt[a[i] % res]) ++ret;
    cnt[a[i] % res]++;
    if (ret > K) {
      for (int j = 1; j <= i; ++j) cnt[a[j] % res]--;
      return false;
    }
  }
  return true;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> a[i];
    for (int j = 1; j < i; ++j) D[abs(a[i] - a[j])]++;
  }
  for (int i = 1; i < maxa; ++i) {
    for (int j = i; j < maxa; j += i) {
      E[i] += D[j];
    }
  }
  for (int res = 1; res < maxa; ++res) {
    if (check(res)) {
      cout << res << '\n';
      return 0;
    }
  }
}

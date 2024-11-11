#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MAXN = (int)3e5 + 5;
const int MOD = (int)998244353;
int n;
ll a[MAXN], sol;
int oddcnt[MAXN], evencnt[MAXN];
int cnt_bits(ll x) {
  int ret = 0;
  for (int i = 0; i < 63; ++i)
    if (x & (1LL << i)) ret++;
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    a[i] = cnt_bits(a[i]);
  }
  int odd_cnt = 0, even_cnt = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    ll temp_sum = a[i], temp_max = a[i];
    for (int j = i - 1; j >= max(1, i - 130); --j) {
      temp_sum += a[j];
      temp_max = max(temp_max, a[j]);
      if (temp_sum % 2 == 0 && temp_max <= temp_sum / 2) sol++;
    }
    sum += a[i];
    if (sum % 2)
      sol += oddcnt[max(1, i - 130) - 1];
    else
      sol += evencnt[max(1, i - 130) - 1];
    sum -= a[i];
    if (sum % 2)
      odd_cnt++;
    else
      even_cnt++;
    oddcnt[i] = odd_cnt;
    evencnt[i] = even_cnt;
    sum += a[i];
  }
  cout << sol;
  return 0;
}

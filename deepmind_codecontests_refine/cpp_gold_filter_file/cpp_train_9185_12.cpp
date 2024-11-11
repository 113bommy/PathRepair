#include <bits/stdc++.h>
using namespace std;
const int inf_int = 1 << 30;
const long long inf_longlong = 1LL << 62;
const long long MOD = 1e9 + 7;
const int N = 2e5 + 5;
long long n, k, a[N];
long long ans;
void read_input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
}
void solve() {
  vector<long long> cnt0(2 * k + 2), cnt0_1(2 * k + 2);
  for (int i = 0; i < n / 2; i++) {
    cnt0[a[i] + a[n - i - 1]]++;
    cnt0_1[min(a[i], a[n - i - 1]) + 1]++,
        cnt0_1[max(a[i], a[n - i - 1]) + k + 1]--;
  }
  for (int i = 1; i <= 2 * k; i++) {
    cnt0_1[i] += cnt0_1[i - 1];
  }
  ans = inf_longlong;
  for (int x = 1; x <= 2 * k; x++) {
    ans = min(ans, cnt0_1[x] - cnt0[x] + (n / 2 - cnt0_1[x]) * 2);
  }
}
void write_output() { cout << ans << '\n'; }
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    read_input(), solve(), write_output();
  }
  return 0;
}

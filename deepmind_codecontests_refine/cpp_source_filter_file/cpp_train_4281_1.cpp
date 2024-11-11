#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 15;
const int MOD = int(1e9) + 7;
int n, q;
vector<long long> ans;
int one_cnt[MAXN];
long long bin_pow[MAXN];
long long bin_pref[MAXN];
void in() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  ans.resize(q + 5);
  string s;
  cin >> s;
  one_cnt[1] = (s[0] == '1');
  for (int i = 1; i < n; ++i) {
    one_cnt[i + 1] = one_cnt[i] + (s[i] == '1');
  }
  bin_pow[0] = 1;
  bin_pref[0] = 1;
  for (int i = 1; i <= n; ++i) {
    bin_pow[i] = (bin_pow[i - 1] * 2) % MOD;
    bin_pref[i] = (bin_pref[i - 1] + bin_pow[i]) % MOD;
  }
  for (int i = 0; i < q; ++i) {
    int L, R;
    cin >> L >> R;
    int one = one_cnt[R] - one_cnt[L - 1];
    int nul_cnt = (R - L + 1) - one;
    long long answer = bin_pref[one - 1];
    long long tmp = (bin_pref[one - 1] * bin_pow[nul_cnt - 1]) % MOD;
    answer = (answer + tmp) % MOD;
    ans[i] = answer;
  }
}
void out() {
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}
int main() {
  in();
  out();
  return 0;
}

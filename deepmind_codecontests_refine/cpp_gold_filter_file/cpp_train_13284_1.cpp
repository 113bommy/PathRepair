#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ct;
map<int, int> cnt;
long long F[777], IF[777];
inline long long mod_pow(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = mod_pow(a, b / 2);
  tmp = (tmp * tmp) % 1000000007;
  if (b & 1) return (tmp * a) % 1000000007;
  return tmp;
}
void init() {
  F[0] = 1;
  for (int i = 1; i < 777; i++) F[i] = (i * F[i - 1]) % 1000000007;
  IF[0] = 1;
  IF[777 - 1] = mod_pow(F[777 - 1], 1000000007 - 2);
  for (int i = 777 - 2; i > 0; i--) IF[i] = ((i + 1) * IF[i + 1]) % 1000000007;
}
inline long long C(long long n, long long k) {
  return (((F[n] * IF[k]) % 1000000007) * IF[n - k]) % 1000000007;
}
long long solve() {
  long long F1 = ct[0];
  vector<long long> dp(F1, 0);
  dp[F1 - 1] = F[F1];
  for (int i = 1; i < n; i++) {
    long long Fi = ct[i];
    vector<long long> next(dp.size() + Fi, 0);
    for (int j = 0; j < (int)dp.size(); j++) {
      if (dp[j] == 0) continue;
      for (int k = 1; k <= min(Fi, (long long)dp.size() + 1); k++) {
        for (int l = 0; l <= min(k, j); l++) {
          long long exist = dp.size() + 1 - j;
          long long need = k - l;
          if (need > exist) continue;
          long long foo =
              (F[Fi] *
               ((((C(exist, need) * C(j, l)) % 1000000007) * C(Fi - 1, k - 1)) %
                1000000007)) %
              1000000007;
          next[j - l + Fi - k] =
              (next[j - l + Fi - k] + (foo * dp[j]) % 1000000007) % 1000000007;
        }
      }
    }
    dp = next;
  }
  return dp[0];
}
inline int get(int x) {
  for (int i = 2; i * i <= x; i++) {
    while (x % (i * i) == 0) x /= (i * i);
  }
  return x;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    x = get(x);
    cnt[x]++;
  }
  for (auto elem : cnt) ct.push_back(elem.second);
  cnt.clear();
  n = ct.size();
  cout << solve() << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (long long)3e5 + 5;
long long a[MAXN];
long long cnt[MAXN];
long long e[MAXN];
set<long long> bad_m = {6,  10, 12, 16, 18, 24, 28, 30,
                        36, 40, 42, 48, 60, 72, 96, 120};
void precalc() {
  for (long long i = 1; i < MAXN; i++) {
    for (long long j = i + i; j < MAXN; j += i) {
      cnt[j]++;
    }
  }
  e[1] = 0;
  for (long long i = 2; i < MAXN; i++) {
    e[i] = e[i - 1] + cnt[i];
  }
}
long long solve(long long n, long long k) {
  long long pos = -1;
  for (long long i = 1; i <= n; i++) {
    if (e[i] >= k) {
      pos = i;
      break;
    }
  }
  set<long long> numbers;
  for (long long i = 1; i <= pos; i++) {
    numbers.insert(i);
  }
  long long cur = e[pos];
  for (long long i = pos / 2 + 1; i <= pos; i++) {
    if (cur > k && cnt[i] == 1) {
      cur--;
      numbers.erase(i);
    }
  }
  cout << "Yes" << endl;
  cout << (long long)numbers.size() << endl;
  for (long long el : numbers) {
    cout << el << " ";
  }
  cout << endl;
  exit(0);
}
long long brute_force(long long n, long long k) {
  long long pos = -1;
  for (long long i = 1; i <= n; i++) {
    if (e[i] >= k) {
      pos = i;
      break;
    }
  }
  long long exceed = e[pos] - k;
  vector<long long> dp(exceed + 5, 0);
  vector<long long> par(exceed + 5, 0);
  dp[0] = 1;
  for (long long x = pos / 2 + 1; x <= pos; x++) {
    for (long long i = exceed; i >= 0; i--) {
      if (dp[i] && i + cnt[x] <= exceed && dp[i + cnt[x]] == 0) {
        dp[i + cnt[x]] = 1;
        par[i + cnt[x]] = x;
      }
    }
  }
  long long fn = exceed;
  set<long long> numbers;
  for (long long i = 1; i <= pos; i++) {
    numbers.insert(i);
  }
  while (fn != 0) {
    numbers.erase(par[fn]);
    fn -= cnt[par[fn]];
  }
  cout << "Yes" << endl;
  cout << (long long)numbers.size() << endl;
  for (long long el : numbers) {
    cout << el << " ";
  }
  exit(0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  precalc();
  long long n, k;
  cin >> n >> k;
  long long pos = -1;
  for (long long i = 1; i <= n; i++) {
    if (e[i] >= k) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    cout << "No" << endl;
    exit(0);
  }
  if (pos <= 120) {
    brute_force(n, k);
  } else {
    solve(n, k);
  }
}

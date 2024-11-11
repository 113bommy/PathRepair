#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int x, long long int n) {
  if (n == 0) return 1;
  if (n % 2) return x * power(x * x, (n - 1) / 2);
  return power(x * x, n / 2);
}
long long int powerm(long long int x, long long int n) {
  if (n == 0) return 1;
  if (n % 2)
    return (x * powerm((x * x) % 1000000007, (n - 1) / 2)) % 1000000007;
  return powerm((x * x) % 1000000007, n / 2);
}
long long int cache[5005][5005];
vector<pair<long long int, long long int> > voter;
long long int dp(int n, int taken) {
  if (n == 0) {
    if (taken >= voter[n].first) {
      return 0;
    } else {
      return voter[n].second;
    }
  }
  long long int &mem = cache[n][taken];
  if (mem != -1) {
    return mem;
  }
  long long int ans = LLONG_MAX;
  if (taken >= voter[n].first) {
    ans = min(ans, dp(n - 1, taken + 1));
  } else if (taken + n >= voter[n].first) {
    ans = min(ans, dp(n - 1, taken));
  }
  ans = min(ans, voter[n].second + dp(n - 1, taken + 1));
  return mem = ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    voter.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        cache[i][j] = -1;
      }
    }
    long long int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      voter.push_back({x, y});
    }
    sort(voter.begin(), voter.end());
    cout << dp(n - 1, 0) << "\n";
  }
  return 0;
}

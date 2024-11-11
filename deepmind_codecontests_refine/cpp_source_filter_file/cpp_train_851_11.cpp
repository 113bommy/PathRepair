#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<long long, long long> &a,
         const pair<long long, long long> &b) {
  return a.first < b.first;
}
const long long M = 1e9 + 7;
long long n;
vector<pair<long long, long long> > a;
int main() {
  cin >> n;
  a = vector<pair<long long, long long> >(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), cmp);
  vector<long long> dp(n, M);
  vector<long long> dp2(n, 0);
  dp[2] = a[2].first - a[0].first;
  dp2[2] = 3;
  for (long long i = 3; i < n; i++) {
    long long res = a[i].first - a[0].first, resi = i + 1;
    for (long long c = 3; c <= 5; c++) {
      if (i - c < 2) break;
      long long cur = dp[i - c] + a[i].first - a[i - c + 1].first;
      if (cur < res) {
        res = cur;
        resi = c;
      }
    }
    dp[i] = res;
    dp2[i] = resi;
  }
  vector<long long> gs(n, 0);
  long long i = n - 1;
  long long gi = 0;
  while (i >= 0) {
    long long c = dp2[i];
    for (long long j = 0; j < c; j++) {
      long long idx = a[i - j].second;
      gs[idx] = gi;
    }
    i -= c;
    gi++;
  }
  cout << dp[n - 1] << " " << gi + 1 << endl;
  for (long long i = 0; i < n; i++) {
    cout << gs[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}

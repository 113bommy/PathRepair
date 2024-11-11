#include <bits/stdc++.h>
using namespace std;
double divide(double a, double b) { return (double)a / b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n], b[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  vector<pair<long long, long long> > v;
  v.push_back(make_pair(0, b[0]));
  long long dp[n];
  long long lastindex = 0;
  for (long long i = 1; i < n; i++) {
    long long siz = v.size();
    while (lastindex < siz - 1 &&
           (v[lastindex].first + a[i] * v[lastindex].second >
            v[lastindex + 1].first + a[i] * v[lastindex + 1].second))
      lastindex++;
    dp[i] = v[lastindex].first + a[i] * v[lastindex].second;
    while (siz >= 2 &&
           divide(v[siz - 2].first - dp[i], v[siz - 2].second - b[i]) <
               divide(v[siz - 1].first - dp[i], v[siz - 1].second - b[i])) {
      v.pop_back();
      siz -= 2;
    }
    v.push_back(make_pair(dp[i], b[i]));
    lastindex = min(lastindex, siz - 1);
  }
  cout << dp[n - 1] << "\n";
}

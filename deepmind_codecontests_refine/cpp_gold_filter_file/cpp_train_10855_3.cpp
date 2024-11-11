#include <bits/stdc++.h>
using namespace std;
const long long dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const long long dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
                dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const long long mod = 1000000007;
const long long base = 311;
const long long N = 3e5 + 5;
long long n, a[N];
struct three {
  long long ii, jj;
  long long x;
};
void biot() {
  cin >> n;
  long long sum = 0;
  for (long long i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
  if (sum % n != 0) {
    cout << -1 << '\n';
    return;
  }
  vector<three> ans;
  ans.clear();
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      q;
  for (long long i = 2; i <= n; ++i) {
    long long need = (i - a[i] % i) % i;
    a[i] += need;
    ans.push_back({1, i, need});
    ans.push_back({i, 1, a[i] / i});
  }
  for (long long i = 2; i <= n; ++i) ans.push_back({1, i, sum / n});
  cout << ((long long)(ans).size()) << '\n';
  for (three i : ans) cout << i.ii << ' ' << i.jj << ' ' << i.x << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (fopen("cf"
            ".inp",
            "r")) {
    freopen(
        "cf"
        ".inp",
        "r", stdin);
    freopen(
        "cf"
        ".out",
        "w", stdout);
  }
  long long t;
  cin >> t;
  while (t--) biot();
  return 0;
}

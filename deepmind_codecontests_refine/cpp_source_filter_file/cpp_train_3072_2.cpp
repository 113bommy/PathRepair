#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e18;
const long long minN = -1e18;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const int baseHash = 331;
const int bigNumLength = 5000;
const long double PI = acos(-1);
const long long limit = 2e5 + 5;
const long long limit1 = 1e6 + 5;
const long long limit2 = 1e3 + 5;
long long n, x1, x2;
long long k[limit], b[limit];
vector<pair<long long, long long> > ans;
void solveProblem() {
  for (int i = (1); i <= (n); ++i) {
    long long t1 = k[i] * x1 + b[i];
    long long t2 = k[i] * x2 + b[i];
    ans.push_back({t1, t2});
  }
  sort((ans).begin(), (ans).end());
  bool ok = false;
  for (int i = (0); i < (ans.size()); ++i) {
    if (ans[i].first < ans[i + 1].first && ans[i].second > ans[i + 1].second)
      ok = true;
  }
  cout << (ok ? "YES" : "NO") << '\n';
}
void fastInput() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void readInput() {
  cin >> n >> x1 >> x2;
  for (int i = (1); i <= (n); ++i) cin >> k[i] >> b[i];
}
int main() {
  fastInput();
  readInput();
  solveProblem();
}

#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
using ll = long long;
const double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<ll> result(n);
  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
  result.resize(a.size() + b.size());
  return result;
}
using namespace std;
ll dp[100000][100];
class F2CompleteTheProjectsHardVersion {
 public:
  int sol(vector<pair<ll, ll> >& neg, int i, ll r) {
    if (i == neg.size()) return 0;
    if (dp[r + 30000][i] != -1) return dp[r + 30000][i];
    dp[r + 30000][i] = sol(neg, i + 1, r);
    if (neg[i].first <= r && neg[i].second + r > 0)
      dp[r + 30000][i] =
          max(dp[r + 30000][i], 1ll + sol(neg, i + 1, r + neg[i].second));
    return dp[r + 30000][i];
  }
  void solve(std::istream& cin, std::ostream& cout) {
    int n;
    ll r;
    cin >> n >> r;
    vector<pair<ll, ll> > pos, neg;
    for (int i = 0; i < n; i++) {
      ll x, y;
      cin >> x >> y;
      if (y >= 0) {
        pos.push_back({x, y});
      } else
        neg.push_back({x, y});
    }
    int ans = 0;
    sort(pos.begin(), pos.end());
    for (pair<ll, ll> p : pos) {
      if (p.first <= r) {
        r += p.second;
        ans++;
      }
    }
    sort(neg.begin(), neg.end(),
         [r](pair<ll, ll> const& a, pair<ll, ll> const& b) -> bool {
           return a.first + a.second - (b.first + b.second) > 0;
         });
    for (int i = 0; i < 100000; i++)
      for (int j = 0; j < neg.size(); j++) dp[i][j] = -1;
    ans += sol(neg, 0, r);
    cout << (ans) << endl;
  }
};
int main() {
  F2CompleteTheProjectsHardVersion solver;
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

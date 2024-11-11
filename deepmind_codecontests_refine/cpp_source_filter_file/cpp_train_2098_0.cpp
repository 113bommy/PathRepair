#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3ffffff;
const int MOD = 1e9 + 7;
const long long HASH_KEY = 6151;
const long long HASH_MOD = 1610612741;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<long long, long long> > p(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p[i] = pair<long long, long long>(x, y - x * x);
  }
  sort((p).begin(), (p).end(), greater<pair<long long, long long> >());
  vector<pair<long long, long long> > stk(n);
  int top = 0;
  for (int i = 0; i < n; ++i) {
    auto cross = [&](const pair<long long, long long> &o,
                     const pair<long long, long long> &a,
                     const pair<long long, long long> &b) {
      return (a.first - o.first) * (b.second - o.second) -
             (a.second - o.second) * (b.first - o.first);
    };
    while (top >= 2 && cross(stk[top - 2], stk[top - 1], p[i]) <= 0) {
      --top;
    }
    stk[top++] = p[i];
  }
  while (top >= 2 && stk[top - 2].first == stk[top - 1].first) {
    --top;
  }
  cout << top - 1 << "\n";
  return 0;
}

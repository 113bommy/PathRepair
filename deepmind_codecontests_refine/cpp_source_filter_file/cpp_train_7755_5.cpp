#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const string XXX[] = {"LM", "MW", "LW"};
struct node {
  ll x, y, z, code, sum;
};
int n, k, l[30], m[30], w[30], anscode[30];
vector<node> part1;
map<pair<int, int>, node> part2;
void dq(int ind, int lim, ll x, ll y, ll z, ll code, ll sum, bool ispart1) {
  if (ind > lim) {
    if (ispart1)
      part1.push_back({x, y, z, code, sum});
    else {
      pair<int, int> key = {x - z, y - z};
      node val = {x - z, y - z, 0, code, sum};
      auto it = part2.find(key);
      if (it == part2.end() || it->second.sum < val.sum) part2[key] = val;
    }
  } else {
    dq(ind + 1, lim, x + l[ind], y + m[ind], z, code * 3, sum + l[ind] + m[ind],
       ispart1);
    dq(ind + 1, lim, x, y + m[ind], z + w[ind], code * 3 + 1,
       sum + m[ind] + w[ind], ispart1);
    dq(ind + 1, lim, x + l[ind], y, z + w[ind], code * 3 + 2,
       sum + l[ind] + w[ind], ispart1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> l[i] >> m[i] >> w[i];
  k = n / 2;
  dq(1, k, 0, 0, 0, 0, 0, true);
  dq(k + 1, n, 0, 0, 0, 0, 0, false);
  ll ans = -1, code1 = -1, code2 = -1;
  for (auto &A : part1) {
    ll x2 = A.z - A.x;
    ll y2 = A.z - A.y;
    auto it = part2.find({x2, y2});
    if (it != part2.end() && ans < A.sum + it->second.sum) {
      ans = A.sum + it->second.sum;
      code1 = A.code;
      code2 = it->second.code;
    }
  }
  if (ans == -1)
    cout << "Impossible";
  else {
    for (int i = k; i > 0; --i) {
      anscode[i] = code1 % 3;
      code1 /= 3;
    }
    for (int i = n; i > k; --i) {
      anscode[i] = code2 % 3;
      code2 /= 3;
    }
    for (int i = 1; i <= n; ++i) cout << XXX[anscode[i]] << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;
using vc = vector<char>;
using vll = vector<ll>;
ll k, total, avg_size;
vector<vll> boxes;
vll box_sizes;
unordered_map<ll, bool> exists;
unordered_map<ll, ll> region;
unordered_map<ll, bool> visited;
ll f(ll item) {
  ll s1 = box_sizes[region[item]];
  ll ans = avg_size - (s1 - item);
  if (exists[ans]) return ans;
  return INF;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> k;
  for (ll i = (0); i < (k); ++i) {
    ll l;
    cin >> l;
    boxes.push_back(vll(l));
    ll t = 0;
    for (ll j = (0); j < (l); ++j) {
      ll a;
      cin >> a;
      t += a;
      total += a;
      exists[a] = true;
      boxes[i][j] = a;
    }
    box_sizes.push_back(t);
  }
  if (total % k != 0) {
    cout << "No" << endl;
    return 0;
  }
  avg_size = total / k;
  for (ll i = (0); i < (k); ++i) {
    for (ll item : boxes[i]) {
      region[item] = i;
    }
  }
  unordered_map<ll, ll> cycles;
  cycles[0] = 0;
  for (auto pr : region) {
    int s = pr.first;
    if (visited[s]) continue;
    ll mask = 0;
    ll p = s;
    do {
      visited[p] = true;
      if (mask & (1 << region[p])) {
        p = INF;
        break;
      }
      mask |= (1 << region[p]);
      p = f(p);
    } while (p != INF && p != s);
    if (p == INF) continue;
    cycles[mask] = s;
  }
  vll dp(1 << k);
  vll trace(1 << k);
  dp[0] = true;
  for (int m = 0; m < (1 << k); ++m) {
    for (int s = m; s; s = (s - 1) & m) {
      if (dp[m ^ s] && (cycles.find(s) != cycles.end())) dp[m] = true;
    }
  }
  if (!dp[(1 << k) - 1]) {
    cout << "No" << endl;
    return 0;
  }
  vll take(k);
  vll move(k);
  int a = (1 << k) - 1;
  while (a != 0) {
    for (int s = a; s; s = (s - 1) & a) {
      if (dp[a ^ s] && (cycles.find(s) != cycles.end())) {
        vll temp;
        ll start = cycles[s];
        do {
          temp.push_back(start);
          start = f(start);
        } while (start != cycles[s]);
        for (ll i = (0); i < (temp.size()); ++i) {
          take[region[temp[i]]] = temp[i];
          move[region[temp[i]]] =
              region[temp[(i - 1 + temp.size()) % temp.size()]];
        }
        a = a ^ s;
        break;
      }
    }
  }
  cout << "Yes" << endl;
  for (ll i = (0); i < (k); ++i) {
    cout << take[i] << " " << move[i] + 1 << endl;
  }
}

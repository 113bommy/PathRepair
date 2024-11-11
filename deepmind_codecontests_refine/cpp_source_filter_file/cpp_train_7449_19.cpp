#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct custom {
  bool operator()(vector<ll> a, vector<ll> b) { return abs(a[1]) > abs(b[1]); }
};
void solve() {
  int n;
  ll k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  int count = 0, index = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    count += (a[i] < 0);
  }
  count %= 2;
  if (count == 0) {
    for (int i = 0; i < n; i++) {
      if (abs(a[i]) < abs(a[index])) {
        index = i;
      }
    }
    if (a[index] <= 0) {
      while (k && a[index] <= 0) {
        a[index] += x;
        k--;
      }
    } else {
      while (k && a[index] >= 0) {
        a[index] -= x;
        k--;
      }
    }
  }
  priority_queue<vector<ll>, vector<vector<ll>>, custom> store;
  for (int i = 0; i < n; i++) {
    store.push({i, a[i]});
  }
  while (k--) {
    vector<ll> curr = store.top();
    store.pop();
    if (a[curr[0]] < 0) {
      a[curr[0]] -= x;
    } else {
      a[curr[0]] += x;
    }
    store.push({curr[0], a[curr[0]]});
  }
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}

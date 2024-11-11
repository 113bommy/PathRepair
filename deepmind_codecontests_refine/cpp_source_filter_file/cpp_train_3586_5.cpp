#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ll m, n, k;
ll judge(ll mid) {
  ll sum = 0;
  for (long long int i = (1); i <= (n); i++) {
    sum += min(m, mid / i);
  }
  return sum;
}
void solve() {
  cin >> n >> m >> k;
  ll left = 1, right = n * m;
  ll mid = (left + right) / 2;
  while (abs(left - right) > 1) {
    mid = (left + right) / 2;
    ll great = judge(mid);
    if (great > k) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if (judge(left) == k) {
    cout << left;
  } else {
    cout << right;
  }
}
int main() {
  if (true) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  solve();
}

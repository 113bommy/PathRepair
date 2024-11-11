#include <bits/stdc++.h>
using ll = long long;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
struct comp {
  bool operator()(const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) const {
    return lhs.first > rhs.first;
  }
};
void solveA() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  if (s == "0") {
    cout << "0" << endl;
    return;
  }
  string answer = "1";
  for (char c : s) {
    if (c == '0') {
      answer += "0";
    }
  }
  cout << answer << endl;
  return;
}
void solveB() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (k < n) {
    cout << k + 1 << ' ' << 1 << endl;
    return;
  }
  k -= n - 1;
  ll diff_n = (k - 1) / (m - 1);
  ll diff_m = (k - 1) % (m - 1);
  ll tmp = (k - 1) % (2 * m - 2);
  if (tmp / (m - 1)) {
    cout << n - diff_n << ' ' << m - diff_m << endl;
  } else {
    cout << n - diff_n << ' ' << diff_m + 2 << endl;
  }
}
struct segment_info {
  bool operator<(const segment_info& a) const {
    if (left == a.left) {
      return right < a.right;
    }
    return left < a.left;
  }
  segment_info(ll l, ll r, ll i) : left(l), right(r), ind(i) {}
  ll left;
  ll right;
  ll ind;
};
void solveC() {
  ll n;
  cin >> n;
  vector<segment_info> v;
  for (int i = 0; i < n; ++i) {
    ll left;
    ll right;
    cin >> left >> right;
    segment_info s(left, right, i);
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  ll max_right = v[0].right;
  ll last_ind = v[0].ind;
  for (int i = 1; i < n; ++i) {
    if (v[i].right <= max_right) {
      cout << v[i].ind + 1 << ' ' << last_ind + 1 << endl;
      return;
    } else {
      max_right = v[i].right;
      last_ind = v[i].ind;
    }
  }
  cout << -1 << ' ' << -1 << endl;
  return;
}
void solveD() { ll n; }
void solveE() { ll n; }
void solveF() { ll n; }
int main() {
  solveC();
  return 0;
}

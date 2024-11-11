#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& p) {
  out << "[";
  for (int i = 0; i < (int)p.size(); ++i) {
    if (i) out << ", ";
    out << p[i];
  }
  return out << "]";
}
const int INF = (int)2e9 + 1000;
const long long INF64 = (long long)1e18 + 1000;
const int N = (int)2e5 + 1000;
const int MOD = (int)1e9 + 7;
vector<pair<pair<int, int>, int>> a;
int n, k, h;
long double eps = 1e-21;
bool ok(long double x) {
  long double curh = h * k;
  for (int i = 0; i < n; ++i) {
    if (curh == 0) {
      break;
    }
    if (curh / a[i].first.second <= x - eps) {
      curh -= h;
    }
  }
  return curh == 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> h;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first.first;
    a[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first.second;
    a[i].second = i;
  }
  sort(a.rbegin(), a.rend());
  long double l = 0, r = 1e21;
  for (int _ = 0; _ < (int)300; ++_) {
    long double m = (r + l) / 2;
    if (ok(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  long long curh = k * h;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (curh == 0) {
      break;
    }
    if (curh / a[i].first.second <= r - eps) {
      curh -= h;
      ans.push_back(a[i].second + 1);
    }
  }
  assert(curh == 0);
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << ' ';
  }
}

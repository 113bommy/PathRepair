#include <bits/stdc++.h>
using namespace std;
bool mysort(const pair<int64_t, int64_t> &a, const pair<int64_t, int64_t> &b) {
  return (a.second > b.second);
}
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void show_vec(vector<int64_t> &v) {
  for (int64_t i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
bool check_prime(int64_t n) {
  if (n <= 1) return false;
  if (n < 4) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int64_t i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
void solve() {
  int64_t n, q, i, tmax = 0, tmp, a, b;
  cin >> n >> q;
  deque<int64_t> d;
  vector<pair<int64_t, int64_t> > v;
  for (i = 0; i < n; i++) {
    cin >> tmp;
    d.push_back(tmp);
    tmax = max(tmax, tmp);
    if (i == 0)
      a = tmp;
    else if (i == 1)
      b = tmp;
    else if (v.size() == 0)
      v.push_back({a, b});
  }
  if (n > 2) {
    while (d.front() != tmax) {
      int64_t x = d.front();
      d.pop_front();
      int64_t y = d.front();
      d.pop_front();
      int64_t z = d.front();
      v.push_back({max(x, y), z});
      d.push_front(max(x, y));
      d.push_back(min(x, y));
    }
  }
  vector<int64_t> vec;
  deque<int64_t> f = d;
  bool ok = false;
  while (!(f.empty())) {
    if (ok) vec.push_back(f.front());
    f.pop_front();
    ok = true;
  }
  while (q--) {
    cin >> tmp;
    tmp--;
    if (n == 2) {
      if (tmp == 0)
        cout << a << " " << b << endl;
      else
        cout << max(a, b) << " " << min(a, b) << endl;
    } else {
      if (tmp < v.size())
        cout << v[tmp].first << " " << v[tmp].second << endl;
      else {
        cout << tmax << " ";
        tmp -= (v.size() - 1);
        cout << vec[(tmp) % (vec.size())] << endl;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}

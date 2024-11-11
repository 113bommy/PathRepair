#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool mod(long double a, long double b) { return a / b - floor(a / b); }
long long f3(multiset<long long> ciel, vector<long long> atk) {
  long long i, j, first, second, sum, ans = 0;
  sum = atk.size();
  for (i = 0; i < atk.size(); i++) {
    first = atk[i];
    auto it = ciel.lower_bound(first);
    if (it == ciel.end()) return 0;
    ans += *it - first;
    ciel.erase(it);
  }
  for (auto it = (ciel).begin(); it != (ciel).end(); it++) {
    ans += *it;
  }
  return ans;
}
long long f1(multiset<long long> ciel, vector<long long> atk,
             vector<long long> def) {
  long long n1, n2, m, i, j, first, second, sum, ans, abc;
  n1 = atk.size();
  n2 = def.size();
  m = ciel.size();
  sum = n1 + n2;
  ans = 0;
  for (i = 0; i < n2; i++) {
    first = def[i];
    auto it = ciel.upper_bound(first);
    if (it != ciel.end()) {
      ciel.erase(it);
      sum--;
    }
  }
  if (sum == n1) {
    abc = f3(ciel, atk);
  }
  for (i = 0; i < n1; i++) {
    first = atk[i];
    if (ciel.size() > 0) {
      auto it = ciel.end();
      it--;
      second = *it;
      if (second >= first) {
        ans += (second - first);
        sum--;
        ciel.erase(it);
      }
    }
  }
  if (sum == 0) {
    for (auto it = (ciel).begin(); it != (ciel).end(); it++) {
      ans += *it;
    }
  }
  return max(ans, abc);
}
long long f2(multiset<long long> ciel, vector<long long> atk,
             vector<long long> def) {
  long long n1, n2, m, i, j, first, second, sum, ans;
  n1 = atk.size();
  n2 = def.size();
  m = ciel.size();
  sum = n1 + n2;
  ans = 0;
  for (i = 0; i < n1; i++) {
    first = atk[i];
    if (ciel.size() > 0) {
      auto it = ciel.end();
      it--;
      second = *it;
      if (second >= first) {
        ans += (second - first);
        sum--;
        ciel.erase(it);
      }
    }
  }
  for (i = 0; i < n2; i++) {
    first = def[i];
    auto it = ciel.upper_bound(first);
    if (it != ciel.end()) {
      ciel.erase(it);
      sum--;
    }
  }
  if (sum == 0) {
    for (auto it = (ciel).begin(); it != (ciel).end(); it++) {
      ans += *it;
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, first, n, m;
  multiset<long long> ciel;
  vector<long long> def, atk;
  cin >> n >> m;
  string s;
  for (i = 0; i < n; i++) {
    cin >> s >> first;
    if (s == "ATK") {
      atk.push_back(first);
    } else {
      def.push_back(first);
    }
  }
  for (i = 0; i < m; i++) {
    cin >> first;
    ciel.insert(first);
  }
  sort((atk).begin(), (atk).end());
  sort((def).begin(), (def).end());
  long long x1 = f1(ciel, atk, def);
  long long x2 = f2(ciel, atk, def);
  cout << max(x1, x2);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> ma;
vector<long long int> cases;
string s;
bool find(long long int len) {
  long long int val = ma[len];
  long long int a = 0;
  long long int m = 1e9 + 9;
  long long int p = 31, n = s.size(), i;
  long long int p_pow = 1;
  for (i = 1; i <= len && i < n - 1; ++i) {
    a *= p;
    a += (s[i] - 'a' + 1);
    a %= m;
    p_pow *= p;
    p_pow %= m;
  }
  if (a == val) return true;
  for (i = len + 1; i < n - 1; ++i) {
    a *= p;
    a = (a - p_pow * (s[i - len] - 'a' + 1) + s[i] - 'a' + 1 + m) % m;
    if (a == val) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, m, n, i, f = 0, j, ans = 0;
  cin >> s;
  n = s.length();
  long long int suff = 0;
  long long int pre = 0;
  long long int p_pow = 1;
  long long int p = 31;
  m = 1e9 + 9;
  for (i = 0; i < n - 1; ++i) {
    suff *= p;
    suff += (s[i] - 'a' + 1);
    suff %= m;
    pre += p_pow * (s[n - i - 1] - 'a' + 1);
    p_pow *= p;
    p_pow %= m;
    pre %= m;
    if (suff == pre) {
      f = 1;
      ma[i + 1] = suff;
      cases.push_back(i + 1);
    }
  }
  if (f == 0) {
    cout << "Just a legend";
    return 0;
  }
  if (!find(cases[0])) {
    cout << "Just a legend";
    return 0;
  }
  long long int k = cases.size();
  if (find(cases[k - 1])) {
    for (i = 0; i < cases[k - 1]; ++i) {
      cout << s[i];
    }
    return 0;
  }
  long long int l = 0;
  long long int r = k - 1;
  long long int mid;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (find(cases[mid])) {
      ans = cases[mid];
      l = mid + 1;
    } else
      r = mid - 1;
  }
  for (i = 0; i < ans; ++i) cout << s[i];
  return 0;
}

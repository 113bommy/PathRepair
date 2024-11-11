#include <bits/stdc++.h>
using namespace std;
bool can_take_over(string &s, string &t, vector<long long> &a, long long idx) {
  long long n = (long long)s.length(), m = (long long)t.length();
  vector<bool> can_take(n, true);
  for (long long i = 0; i <= idx; i++) {
    can_take[a[i]] = false;
  }
  long long i_t = 0, i_s = 0;
  while (i_t < m) {
    while (i_s < n && (s[i_s] != t[i_t] || !can_take[i_s])) {
      i_s++;
    }
    if (i_s == n) {
      return false;
    }
    i_t++;
    i_s++;
  }
  return true;
}
void test_case() {
  string t, p;
  cin >> t >> p;
  long long n = (long long)t.length();
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  if (t == p) {
    cout << 0 << "\n";
    return;
  }
  long long start = -1;
  for (long long step = n; step >= 1; step /= 2) {
    while (start + step < n && can_take_over(t, p, a, start + step)) {
      start += step;
    }
  }
  cout << start + 1 << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  while (t--) {
    test_case();
  }
  return 0;
}

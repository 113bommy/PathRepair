#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = (long long)1 << 62;
const int mod = 1e9 + 7;
const long long maxn = 2 * 1e5 + 10;
long long n, k, x, a[maxn], sign;
set<pair<long long, long long> > s, ans;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> x;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0LL) sign++;
    s.insert({a[i], i});
  }
  auto t = s.lower_bound(make_pair(0LL, -1LL));
  while (t->first == 0LL && k > 0) {
    long long t1 = t->first + x, t2 = t->second;
    if (sign % 2 == 0LL) {
      t1 -= 2 * x;
      sign++;
    }
    s.erase(t);
    s.insert(make_pair(t1, t2));
    k--;
    t = s.lower_bound(make_pair(0LL, -1LL));
  }
  while (k > 0LL) {
    t = s.lower_bound(make_pair(0LL, -1LL));
    long long t1, t2;
    if (sign % 2 == 0LL) {
      if (t != s.begin() && t != s.end()) {
        auto temp = prev(t);
        if (abs(temp->first) < t->first) {
          t1 = temp->first + x, t2 = temp->second;
          if (t1 >= 0LL) sign++;
          s.erase(temp);
        } else {
          t1 = t->first - x, t2 = t->second;
          if (t1 < 0LL) sign++;
          s.erase(t);
        }
      } else if (t == s.begin()) {
        t1 = t->first - x, t2 = t->second;
        if (t1 < 0LL) sign++;
        s.erase(t);
      } else {
        auto temp = prev(t);
        t1 = temp->first + x, t2 = temp->second;
        if (t1 >= 0LL) sign++;
        s.erase(temp);
      }
    } else {
      if (t != s.begin() && t != s.end()) {
        auto temp = prev(t);
        if (abs(temp->first) < t->first) {
          t1 = temp->first - x, t2 = temp->second;
          s.erase(temp);
        } else {
          t1 = t->first + x, t2 = t->second;
          s.erase(t);
        }
      } else if (t == s.begin()) {
        t1 = t->first + x, t2 = t->second;
        s.erase(t);
      } else {
        auto temp = prev(t);
        t1 = temp->first - x, t2 = temp->second;
        s.erase(temp);
      }
    }
    s.insert(make_pair(t1, t2));
    k--;
  }
  for (auto it = s.begin(); it != s.end(); ++it)
    ans.insert(make_pair(it->second, it->first));
  for (auto it = ans.begin(); it != ans.end(); ++it) cout << it->second << ' ';
  return 0;
}

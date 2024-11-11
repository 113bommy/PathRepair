#include <bits/stdc++.h>
using namespace std;
void count_sort(vector<long long>& p, vector<long long>& c) {
  long long n = p.size();
  vector<long long> cnt(n);
  for (auto x : c) cnt[x]++;
  vector<long long> pos(n), p_new(n);
  pos[0] = 0;
  for (long long i = 1; i < n; i++) pos[i] = pos[i - 1] + cnt[i - 1];
  for (auto x : p) {
    long long i = c[x];
    p_new[pos[i]] = x;
    pos[i]++;
  }
  p = p_new;
}
int main() {
  string s, t, str;
  cin >> s >> t;
  str = s;
  long long sz = s.size();
  s = s + '#';
  s = s + t;
  s = s + '$';
  long long n = s.size();
  vector<long long> p(n), c(n);
  {
    std::vector<pair<char, long long>> a(n);
    for (long long i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for (long long i = 0; i < n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for (long long i = 1; i < n; i++) {
      if (a[i].first == a[i - 1].first)
        c[p[i]] = c[p[i - 1]];
      else
        c[p[i]] = c[p[i - 1]] + 1;
    }
  }
  long long k = 0;
  while ((1 << k) < n) {
    for (long long i = 0; i < n; i++) {
      p[i] = (p[i] - (1 << k) + n) % n;
    }
    count_sort(p, c);
    vector<long long> c_new(n);
    c_new[p[0]] = 0;
    for (long long i = 1; i < n; i++) {
      pair<long long, long long> prev = {c[p[i - 1]],
                                         c[(p[i - 1] + (1 << k)) % n]};
      pair<long long, long long> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
      if (now == prev)
        c_new[p[i]] = c_new[p[i - 1]];
      else
        c_new[p[i]] = c_new[p[i - 1]] + 1;
    }
    c = c_new;
    k++;
  }
  k = 0;
  vector<long long> lcp(n);
  for (long long i = 0; i < n - 1; i++) {
    long long pi = c[i];
    long long j = p[pi - 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[pi] = k;
    k = max(k - 1, 0ll);
  }
  long long ans = LLONG_MAX;
  for (long long i = 2; i < n; i++) {
    if ((p[i] > sz && p[i - 1] < sz) || (p[i] < sz && p[i - 1] > sz)) {
      long long val;
      if (i + 1 < n)
        val = lcp[i - 1];
      else
        val = max(lcp[i - 1], lcp[i + 1]);
      long long temp = lcp[i] - val;
      if (temp > 0) {
        ans = min(val + 1, ans);
      }
    }
  }
  if (ans == LLONG_MAX) {
    if (str == t)
      cout << str.size();
    else
      cout << -1;
    return 0;
  }
  cout << ans;
  return 0;
}

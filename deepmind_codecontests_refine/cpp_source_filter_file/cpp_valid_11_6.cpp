#include <bits/stdc++.h>
#pragma GCC optimise("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.second > b.first * a.second;
}
void run_case() {
  long long n;
  cin >> n;
  vector<string> a(n);
  long long max_words = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (char x = 'a'; x <= 'e'; ++x) {
    long long cur = 0;
    vector<pair<long long, long long>> tmp;
    for (long long i = 0; i < n; ++i) {
      long long g = 0, ng = 0;
      for (auto elem : a[i]) {
        if (elem == x)
          g++;
        else
          ng++;
      }
      tmp.emplace_back(g, ng);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    long long tg = 0, tng = 0;
    for (auto elem : tmp) {
      if (tg + elem.first > tng + elem.second) {
        cur++;
        tg += elem.first;
        tng += elem.second;
      }
    }
    max_words = max(max_words, cur);
  }
  cout << max_words << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long test_case = 1;
  cin >> test_case;
  while (test_case--) {
    run_case();
  }
  return 0;
}

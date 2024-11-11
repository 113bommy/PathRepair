#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > f(string s) {
  vector<pair<long long, long long> > a;
  for (long long i = 0; i < s.length(); i++) {
    long long j = i;
    while (j < s.length() && s[j] == s[i]) j++;
    a.emplace_back(s[i] - 'a', j - i);
    i = j - 1;
  }
  return a;
}
signed main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a(n);
  for (long long i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
  if (n == 2) {
    cout << "1";
    exit(0);
  }
  sort(a.begin(), a.end());
  long long ind = 0;
  bool fst = true;
  bool sec = true;
  long long k = a[1].first - a[0].first;
  for (long long i = 1; i < n; i++) {
    if (a[i].first - a[i - 1].first == k) continue;
    if (fst) {
      fst = false, ind = i;
      if (i != n - 1 && a[i + 1].first - a[i - 1].first != k) sec = false;
      i++;
    } else
      sec = false;
  }
  if (fst != sec) {
    cout << a[ind].second + 1 << " ";
  } else {
    bool loc = true;
    k = a[2].first - a[1].first;
    for (long long i = 2; i < n; i++) {
      if (a[i].first - a[i - 1].first != k) loc = false;
    }
    if (loc)
      cout << a[0].second + 1;
    else {
      loc = true;
      k = a[2].first - a[0].first;
      for (long long i = 3; i < n; i++)
        if (a[i].first - a[i - 1].first != k) loc = false;
      if (loc)
        cout << a[1].second + 1 << " ";
      else
        cout << "-1";
    }
  }
}

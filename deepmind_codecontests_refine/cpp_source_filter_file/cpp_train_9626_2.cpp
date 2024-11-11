#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n;
  vector<long long> a;
  vector<long long> b;
  long long temp;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    a.push_back(temp);
  }
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> temp;
    b.push_back(temp);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long teama = 0;
  long long teamb = 0;
  long long ans = -100000000000;
  for (long long i = 0; i < n; i++) {
    if (i > 0 && a[i] == a[i - 1]) {
      continue;
    }
    auto ind = lower_bound(b.begin(), b.end(), a[i]);
    long long tempa = 2 * (i) + 3 * (n - i);
    long long tempb = 2 * (ind - b.begin()) + 3 * (m - (ind - b.begin()));
    if ((tempa - tempb) > ans) {
      teama = tempa;
      teamb = tempb;
      ans = teama - teamb;
    }
    if ((tempa - tempb) == ans && tempa > teama) {
      teama = tempa;
      teamb = tempb;
    }
  }
  long long i = n - 1;
  auto ind = lower_bound(b.begin(), b.end(), a[n - 1] + 1);
  long long tempa = 2 * (i) + 3 * (n - i);
  long long tempb = 2 * (ind - b.begin()) + 3 * (m - (ind - b.begin()));
  if ((tempa - tempb) > ans) {
    teama = tempa;
    teamb = tempb;
    ans = teama - teamb;
  }
  if ((tempa - tempb) == ans && tempa > teama) {
    teama = tempa;
    teamb = tempb;
  }
  for (long long i = 0; i < m; i++) {
    if (i > 0 && b[i] == b[i - 1]) {
      continue;
    }
    auto ind = lower_bound(a.begin(), a.end(), b[i]);
    long long tempb = 2 * (i) + 3 * (m - i);
    long long tempa = 2 * (ind - a.begin()) + 3 * (n - (ind - a.begin()));
    if ((tempa - tempb) > ans) {
      teama = tempa;
      teamb = tempb;
      ans = teama - teamb;
    }
    if ((tempa - tempb) == ans && tempa > teama) {
      teama = tempa;
      teamb = tempb;
    }
  }
  i = m - 1;
  ind = lower_bound(a.begin(), a.end(), b[m - 1] + 1);
  tempb = 2 * (i) + 3 * (m - i);
  tempa = 2 * (ind - a.begin()) + 3 * (n - (ind - a.begin()));
  if ((tempa - tempb) > ans) {
    teama = tempa;
    teamb = tempb;
    ans = teama - teamb;
  }
  if ((tempa - tempb) == ans && tempa > teama) {
    teama = tempa;
    teamb = tempb;
  }
  cout << teama << ":" << teamb << endl;
}

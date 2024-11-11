#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  unsigned long long b;
  unsigned p;
  unsigned t;
  cin >> n >> k >> b;
  if (k >= n - 1) {
    unsigned long long S = 0;
    for (int i = 0; i < n - 1; ++i) {
      cin >> t;
      S += t;
    }
    if (S > b)
      cout << 1;
    else
      cout << n;
    return 0;
  }
  vector<pair<unsigned, unsigned> > v(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end(), greater<pair<unsigned, unsigned> >());
  unsigned m = n - 1;
  unsigned long long s = 0;
  for (int i = 0; i < k - 1; ++i) {
    m = min(m, v[i].second);
    s += v[i].first;
  }
  if (s + v[k - 1].first <= b) {
    cout << n;
    return 0;
  }
  for (int i = k - 1; i < n - 1; ++i) {
    if (m > v[i].second && s + v[i].first > b) m = v[i].second;
  }
  cout << m + 1;
  return 0;
}

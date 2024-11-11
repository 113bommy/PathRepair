#include <bits/stdc++.h>
using namespace ::std;
vector<pair<unsigned long long, unsigned long long> > v;
unsigned long long a[1000000];
int main() {
  unsigned long long i, j, k, n, l;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    cin >> l;
    v.push_back(make_pair(a[i], l));
  }
  sort(v.begin(), v.end());
  multiset<unsigned long long, greater<unsigned long long> > s;
  unsigned long long ans = 0, prevsum = 0;
  for (i = 0; i < n;) {
    j = i + 1;
    s.insert(v[i].second);
    unsigned long long sum = v[i].second + prevsum;
    while (j < n && v[j].first == v[i].first) {
      s.insert(v[j].second);
      sum += v[j].second;
      j++;
    }
    unsigned long long gap = 10000000000000;
    unsigned long long num = s.size();
    if (j != n) {
      gap = v[j].first - v[i].first;
    }
    sum -= (*s.begin());
    s.erase(s.begin());
    k = 0;
    while (k < min(num - 1, gap - 1)) {
      ans = ans + (k + 1) * (*s.begin());
      sum -= (*s.begin());
      s.erase(s.begin());
      k++;
    }
    if (j != n) ans += (sum * (gap));
    prevsum = sum;
    i = j;
  }
  k = 0;
  while (!s.empty()) {
    ans = ans + (k + 1) * (*s.begin());
    s.erase(s.begin());
    k++;
  }
  cout << ans << endl;
  return 0;
}

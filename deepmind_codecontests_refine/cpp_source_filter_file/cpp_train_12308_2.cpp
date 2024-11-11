#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > a;
multiset<long long> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, t, m, sum = 0, curr, ans = 0;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  sort(a.begin(), a.end());
  s.insert(a[0].second);
  curr = a[0].first;
  sum = a[0].second;
  bool flag = false;
  for (int i = 1; i < n; i++) {
    if (a[i].first != curr) {
      if (s.size() == 0) {
        curr = a[i].first;
      } else {
        sum -= *prev(s.end());
        s.erase(*prev(s.end()));
        ans += sum;
        curr++;
      }
      i--;
      continue;
    }
    while (a[i].first == curr) {
      sum += a[i].second;
      s.insert(a[i].second);
      i++;
      if (i == n) {
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
    i--;
  }
  while (s.size() != 0) {
    sum -= *prev(s.end());
    s.erase(*prev(s.end()));
    ans += sum;
    curr++;
  }
  cout << ans;
  return 0;
}

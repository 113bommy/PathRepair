#include <bits/stdc++.h>
using namespace std;
int main() {
  multiset<long> b;
  vector<long> q;
  map<long, long long> ans;
  int n, k, temp;
  long long sum;
  cin >> n >> k;
  vector<pair<long, long>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    q.push_back(a[i].first);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
  }
  sort(a.begin(), a.end());
  for (auto c : a) {
    temp = k;
    sum = 0;
    for (auto l : b) {
      if (temp > 0) {
        sum += abs(l);
        temp--;
      } else
        break;
    }
    ans[c.first] = (sum + c.second);
    b.insert(0 - c.second);
  }
  for (auto c : q) {
    cout << ans[c] << " ";
  }
  return 0;
}

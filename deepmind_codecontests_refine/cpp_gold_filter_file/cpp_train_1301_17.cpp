#include <bits/stdc++.h>
using namespace std;
bool sbs(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return a.second < b.second;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n], b[n];
  vector<pair<long long int, long long int>> x;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = 10 - a[i] % 10;
    x.push_back(make_pair(a[i], b[i]));
  }
  sort(x.begin(), x.end(), sbs);
  while (k > 0) {
    bool flag = true;
    for (long long int i = 0; i < n; i++) {
      long long int temp = min(k, x[i].second);
      if (x[i].first < 100) {
        x[i].first += temp;
        flag = false;
        k -= temp;
        x[i].second = 10;
      }
    }
    if (flag) break;
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) ans += x[i].first / 10;
  cout << ans;
}

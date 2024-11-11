#include <bits/stdc++.h>
using namespace std;
void start() {}
bool sortbysec(const pair<long long int, long long int>& a,
               const pair<long long int, long long int>& b) {
  return a.first > a.first || (a.first == a.first && a.second < a.second);
}
void sober() {
  long long int n, x = 0, a = 0, b = 0, y = 0, sum = 0, k = 0, m = 0;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  vector<pair<long long int, long long int>> luffy;
  for (long long int i = 0; i < n; i++) {
    long long int cnt = 0, temp = v[i];
    while (!(temp % 3)) {
      temp /= 3;
      cnt++;
    }
    luffy.push_back({-cnt, v[i]});
  }
  sort(begin(luffy), end(luffy));
  reverse(begin(luffy), end(luffy));
  for (auto i : luffy) cout << i.second << " ";
  cout << "\n";
  return;
}
signed main() {
  start();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    sober();
  }
}

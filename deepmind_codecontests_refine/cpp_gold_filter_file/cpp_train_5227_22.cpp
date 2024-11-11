#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<char> arr(1);
  for (int i = 0; i < s.length(); i++) arr.push_back(s[i]);
  int ans = 0;
  vector<pair<long long int, long long int> > vec(1);
  k--;
  int b = (n - 2 * k) / 2;
  for (int i = 1; i <= n; i++) {
    int next = -1;
    if (i <= 2 * k) {
      if (i % 2 == 1) {
        next = i;
        while (arr[next] != '(') next++;
      } else {
        next = i;
        while (arr[next] != ')') next++;
      }
      vec.push_back(pair<long long int, long long int>(i, next));
      ans++;
      reverse(arr.begin() + i, arr.begin() + next + 1);
    } else {
      if (i + b <= n) {
        next = i;
        while (arr[next] != '(') next++;
      } else {
        next = i;
        while (arr[next] != ')') next++;
      }
      vec.push_back(pair<long long int, long long int>(i, next));
      ans++;
      reverse(arr.begin() + i, arr.begin() + next + 1);
    }
  }
  cout << ans << endl;
  for (int i = 1; i < vec.size(); i++)
    cout << vec[i].first << " " << vec[i].second << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

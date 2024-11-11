#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<long long, int>> arr;
  for (int i = 0; i < n; ++i) {
    long long l, r;
    cin >> l >> r;
    arr.push_back(make_pair(l, 1));
    arr.push_back(make_pair(r + 1, -1));
  }
  sort(arr.begin(), arr.end());
  long long cnt = 1;
  long long s[int(2e5 + 1)];
  memset(s, 0, sizeof s);
  for (int i = 1; i < arr.size(); ++i) {
    s[cnt] += arr[i].first - arr[i - 1].first;
    cnt += arr[i].second;
  }
  for (int i = 1; i <= n; ++i) {
    cout << s[i] << ' ';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int MOD = 1000000007;
const int N = 2e5 + 50;
int n, m;
long long arr[N];
deque<pair<int, int> > deq;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> arr[i], deq.push_back({arr[i] % m, i});
  sort((deq).begin(), (deq).end());
  int req = n / m;
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int cnt = 0;
    while (cnt < req && deq.front().first <= i) {
      pair<int, int> fi = deq.front();
      deq.pop_front();
      ans += i - fi.first;
      cnt++;
      arr[fi.second] += i - fi.first;
    }
    while (cnt < req) {
      pair<int, int> fi = deq.back();
      deq.pop_back();
      ans += (i - fi.first + m) % m;
      cnt++;
      arr[fi.second] += (i - fi.first + m) % m;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) cout << arr[i] << " \n"[i == n - 1];
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
inline long long sum(long long x, long long y, long long cnt) {
  return cnt * (x + y) / 2LL;
}
long long n, m;
long long bSearch(int x, int y) {
  long long ans = -1, ini = x;
  while (x <= y) {
    long long mit = (x + y) / 2;
    long long cnt = mit - ini + 1;
    if (sum(ini, mit, cnt) > m) {
      y = mit - 1;
    } else if (sum(ini, mit, cnt) <= m) {
      ans = mit;
      x = mit + 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  arr.resize(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  arr.push_back(0);
  arr.push_back((long long)1e9 + 1);
  sort((arr).begin(), (arr).end());
  vector<long long> ans;
  long long k = 0;
  for (long long i = 1; i <= n; i++) {
    long long x = arr[i - 1], y = arr[i];
    x++;
    y--;
    if (x > y) continue;
    long long cnt = y - x + 1;
    if (sum(x, y, cnt) <= m) {
      m -= sum(x, y, cnt);
      k += cnt;
      for (long long j = x; j <= y; j++) ans.push_back(j);
    } else if (x <= m) {
      long long tmp = bSearch(x, y);
      k += tmp - x + 1;
      for (long long j = x; j <= tmp; j++) ans.push_back(j);
      break;
    } else
      break;
  }
  cout << k << "\n";
  for (auto x : ans) cout << x << " ";
  cout << "\n";
  return 0;
}

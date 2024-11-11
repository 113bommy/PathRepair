#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  ;
  vector<long long> res(n + 1);
  int start = 0;
  while (n > 0) {
    int mid = 1;
    while (2 * mid + 1 <= n) mid = mid * 2 + 1;
    mid++;
    for (int i = 0; i < mid - 1 + 1; ++i) res[start + i] = mid - i - 1;
    for (int i = mid; i < n + 1; ++i) res[start + i] = i;
    for (int i = mid; i < n + 1; ++i)
      swap(res[start + i], res[start + 2 * mid - i - 1]);
    start += mid;
    n -= mid;
  }
  long long totalRes = 0;
  for (int i = 0; i < res.size() - 1 + 1; ++i) totalRes += i ^ res[i];
  cout << totalRes << '\n';
  for (int i = 0; i < res.size() - 1 + 1; ++i) cout << res[i] << ' ';
}

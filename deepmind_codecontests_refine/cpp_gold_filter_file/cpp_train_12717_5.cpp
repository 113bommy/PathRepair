#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
long long n, m;
vector<long long> v;
long long cnt[300005];
vector<long long> temp;
long long check(long long val) {
  long long i;
  vector<long long> temp;
  temp = v;
  if (m - temp[0] <= val) temp[0] = 0;
  for (i = 1; i < n; i++) {
    long long diff;
    if (temp[i] > temp[i - 1])
      diff = m - temp[i] + temp[i - 1];
    else
      diff = temp[i - 1] - temp[i];
    if (diff <= val) temp[i] = temp[i - 1];
  }
  for (i = 1; i < n; i++)
    if (temp[i] < temp[i - 1]) return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  long long i, x;
  vector<long long> v1;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  long long l = 0, r = 1e18, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      if (mid - 1 >= 0 && check(mid - 1))
        r = mid - 1;
      else
        break;
    } else
      l = mid + 1;
  }
  cout << mid;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n, k, x;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> x;
  long long a[n], mx = INT_MIN;
  map<long long, int, greater<long long>> m, m1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    long long bb = 1;
    while (bb <= a[i]) {
      if (bb & a[i]) m[bb]++;
      bb *= 2;
    }
  }
  vector<long long> shifts;
  long long bit = m.begin()->first;
  for (int i = 0; i < n; i++)
    if (bit & a[i] || ((bit / 2) & a[i])) shifts.push_back(i);
  long long ans = -1;
  for (int i = 0; i < shifts.size(); i++) {
    m1 = m;
    bit = 1;
    while (bit <= a[shifts[i]]) {
      if (bit & a[shifts[i]]) m1[bit]--;
      bit *= 2;
    }
    long long temp = 0;
    for (auto it = m1.begin(); it != m1.end(); it++)
      if (it->second > 0) temp += (it->first);
    long long cu = a[shifts[i]];
    for (int kk = 0; kk < k; kk++) cu *= x;
    temp = temp | cu;
    ans = max(temp, ans);
  }
  cout << ans;
  return 0;
}

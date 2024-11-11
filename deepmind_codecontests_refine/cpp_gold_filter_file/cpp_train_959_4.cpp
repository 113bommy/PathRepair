#include <bits/stdc++.h>
using namespace std;
long long a[400004];
long long go(vector<long long> &temp, long long x) {
  long long p = upper_bound(temp.begin(), temp.end(), x) - temp.begin();
  return p;
}
long long find(vector<long long> &temp, long long x, int i) {
  return go(temp, (1 << (i + 1)) - 1 - x) - go(temp, (1 << i) - x - 1) +
         go(temp, (1 << (i + 2)) - 2 - x) -
         go(temp, (1 << i) + (1 << (i + 1)) - x - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i <= 25; i++) {
    vector<long long> v, temp;
    long long x = 1 << (i + 1);
    for (int j = 1; j <= n; j++) {
      v.push_back(a[j] % x);
    }
    sort(v.begin(), v.end());
    long long one = 0;
    for (auto it : v) {
      one += find(temp, it, i);
      temp.push_back(it);
    }
    if (one & 1) ans += 1 << i;
  }
  cout << ans;
}

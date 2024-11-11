#include <bits/stdc++.h>
const long long mod = 1000000000 + 7;
const long long INF = 9000000000000000000;
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b / (gcd(a, b))); }
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > arr;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    arr.push_back({x, y});
  }
  sort(arr.begin(), arr.end());
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    long long x1 = arr[i].first, y1 = arr[i].second;
    for (long long j = i + 2; j < n; j++) {
      long long x2 = arr[j].first, y2 = arr[j].second;
      long long temp1 = abs(x2 + x1), temp2 = abs(y2 + y1);
      if (temp1 % 2 == 0 && temp2 % 2 == 0) {
        temp1 = x2 + x1;
        temp2 = y2 + y1;
        temp1 /= 2;
        temp2 /= 2;
        pair<long long, long long> temp = {temp1, temp2};
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        if (it != arr.end() && (*it) == temp) cnt++;
      }
    }
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tests = 1;
  while (tests--) {
    solve();
  }
  return 0;
}

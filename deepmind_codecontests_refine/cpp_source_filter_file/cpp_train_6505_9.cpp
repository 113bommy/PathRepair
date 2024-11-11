#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
const int MOD = 1000000007;
const int N = 2e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  long long int sum = 0;
  vector<long long int> a(n), temp;
  for (auto& i : a) {
    cin >> i;
    sum += i;
  }
  long long int t, l = 2, r = 1e10, mid, hi, consumed, studs, time, timee;
  while (l <= r) {
    temp = a;
    mid = (l + r) / 2;
    hi = n - 1;
    consumed = studs = 0;
    while (studs < m && hi >= 0) {
      while (hi >= 0 && !temp[hi]) hi--;
      if (hi < 0) break;
      if (hi + 1 > mid) break;
      time = mid - hi - 1;
      while (time > 0) {
        while (hi >= 0 && !temp[hi]) hi--;
        if (hi < 0) break;
        consumed += min(time, temp[hi]);
        timee = time;
        if (temp[hi] >= time)
          time = 0;
        else
          time -= temp[hi];
        temp[hi] = max(0ll, temp[hi] - timee);
      }
      studs++;
    }
    if (consumed == sum)
      t = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << t;
  return 0;
}

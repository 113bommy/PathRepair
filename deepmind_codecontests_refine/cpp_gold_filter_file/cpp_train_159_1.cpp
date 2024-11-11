#include <bits/stdc++.h>
using namespace std;
long long n, k, s, T;
vector<pair<long long, long long>> cars;
vector<long long> v1;
bool check2(long long x, long long fuelcapacity, long long dist) {
  return x + ((dist - x) * 2) <= fuelcapacity;
}
bool check3(long long mid, long long i, long long x) {
  return (2 * (v1[mid] - v1[i])) <= x;
}
bool check(long long x) {
  long long t = 0;
  for (long long i = 1; i <= k + 1; i++) {
    long long dist = v1[i] - v1[i - 1];
    if (2 * dist <= x) {
      long long l = i;
      long long r = k + 1;
      long long ans = i;
      while (l <= r) {
        long long mid = (l + r) / 2;
        if (check3(mid, i - 1, x)) {
          ans = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      long long newdist = v1[ans] - v1[i - 1];
      t += newdist;
      i = ans;
      continue;
    }
    long long l = 0;
    long long r = dist;
    long long ans = -1;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (check2(mid, x, dist)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (ans == -1) {
      return false;
    }
    t += (2 * ans) + (dist - ans);
  }
  return t <= T;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> s >> T;
  v1.push_back(0);
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    cars.push_back(make_pair(x, y));
  }
  for (long long i = 1; i <= k; i++) {
    long long x;
    cin >> x;
    v1.push_back(x);
  }
  v1.push_back(s);
  sort(v1.begin(), v1.end());
  long long l = 0;
  long long r = 2e9;
  long long ans = 3e9;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  sort(cars.begin(), cars.end());
  for (auto x : cars) {
    if (x.second >= ans) {
      cout << x.first;
      return 0;
    }
  }
  cout << -1;
}

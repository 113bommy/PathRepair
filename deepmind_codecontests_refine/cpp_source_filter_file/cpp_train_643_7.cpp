#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long cnt1l, cnt1d, cnt2r, cnt2d, cnt3up, cnt3r, cnt4up, cnt4l;
void solve() {
  long long n, sx, sy;
  cin >> n >> sx >> sy;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    if (a < sx && b <= sy) {
      cnt3up++;
    }
    if (a < sx && b >= sy) {
      cnt2d++;
    }
    if (a <= sx && b > sy) {
      cnt2r++;
    }
    if (a >= sx && b > sy) {
      cnt1l++;
    }
    if (a > sx && b >= sy) {
      cnt1d++;
    }
    if (a > sx && b <= sy) {
      cnt4up++;
    }
    if (a >= sx && b < sy) {
      cnt4l++;
    }
    if (a <= sx && b < sy) {
      cnt3r++;
    }
  }
  vector<long long> v;
  v.push_back(cnt1d + cnt4up);
  v.push_back(cnt4l + cnt3r);
  v.push_back(cnt3up + cnt2d);
  v.push_back(cnt1l + cnt2r);
  long long mx =
      (v[0] < (v[1] < (v[2] < v[3] ? v[3] : v[2]) ? (v[2] < v[3] ? v[3] : v[2])
                                                  : v[1])
           ? (v[1] < (v[2] < v[3] ? v[3] : v[2]) ? (v[2] < v[3] ? v[3] : v[2])
                                                 : v[1])
           : v[0]);
  vector<pair<long long, long long>> vp = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  cout << mx << "\n";
  for (long long i = 0; i < 4; i++) {
    if (v[i] == mx) {
      cout << sx + vp[i].first << " " << sy + vp[i].second << "\n";
      break;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test;
  test = 1;
  while (test--) {
    solve();
  }
  return 0;
}

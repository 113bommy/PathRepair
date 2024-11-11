#include <bits/stdc++.h>
using namespace std;
struct HASH {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  static uint64_t splitmix64(const pair<long long, long long>& p) {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    long long x = p.first + FIXED_RANDOM, y = p.second + FIXED_RANDOM;
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    y += 0x9e3779b97f4a7c15;
    y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31) ^ y ^ (y >> 31);
  }
  size_t operator()(const pair<long long, long long>& p) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(p);
  }
};
const int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n;
string str;
void solve() {
  int m, a, b, c;
  cin >> n;
  int arr[n];
  for (int i = 0; i < (int)n; i++) cin >> arr[i];
  sort(arr, arr + n);
  if (arr[0] + arr[1] < arr[n - 1]) {
    cout << "1 2 " << n << endl;
    return;
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

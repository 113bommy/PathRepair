#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
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
};
bool is_powerof_2(long long int x) { return x && (!(x & (x - 1))); }
bool Prime[1000001];
void seive() {
  long long int MAX = 1000001;
  memset(Prime, true, sizeof(Prime));
  for (long long int i = 2; i * i < MAX; i++) {
    if (Prime[i]) {
      for (long long int j = i * i; j < MAX; j += i) {
        Prime[j] = false;
      }
    }
  }
  Prime[1] = false;
}
long long int n, d, k;
vector<pair<long long int, long long int>> ans;
void create(long long int i, long long int left, long long int deg,
            long long int& m) {
  if (left == 0 || m > n) return;
  for (long long int j = 1; j <= k - deg; j++) {
    if (m <= n)
      ans.push_back({i, m});
    else
      return;
    m++;
    if (m > n) return;
    create(m - 1, left - 1, 1, m);
  }
}
void solve() {
  cin >> n >> d >> k;
  if (n == 1) {
    if (d != 0 || k != 0)
      cout << "NO\n";
    else
      cout << "YES\n";
    return;
  }
  if (d == 1) {
    if (n != 2)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cout << "1 2\n";
    }
    return;
  }
  if (k == 1) {
    if (n != 2)
      cout << "NO\n";
    else if (n <= d)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cout << "1 2\n";
    }
    return;
  }
  if (n > d) {
    for (long long int i = (1); i < (d + 1); i++) {
      ans.push_back({i, i + 1});
    }
    long long int m = d + 2;
    for (long long int i = (2); i < (d + 1); i++) {
      int left = min(i - 1, d + 1 - i);
      create(i, left, 2, m);
    }
    if (m <= n)
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto x : ans) cout << x.first << " " << x.second << "\n";
    }
  } else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}

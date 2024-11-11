#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long mod = 1e9 + 7;
template <typename T>
void sort(vector<T> &a) {
  sort(a.begin(), a.end());
}
template <typename T>
void printv(vector<T> &arr) {
  for (auto a : arr) cout << a << " ";
  cout << "\n";
}
long long exp(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  if (n % 2) {
    long long s = exp(a, n - 1) % mod;
    return ((s % mod) * (a % mod)) % mod;
  } else {
    long long s = exp(a, n / 2) % mod;
    return ((s % mod) * (s % mod)) % mod;
  }
}
long long max(long long a, long long b) {
  if (a < b) return b;
  return a;
}
int max(int a, int b, int c) { return max(max(a, b), max(b, c)); }
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int min(int a, int b, int c) { return min(min(a, b), min(b, c)); }
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int max(int a, int b, int c, int d) { return max(max(a, b), max(c, d)); }
struct celeb {
  int x;
  int y;
  int t;
  void print() { cout << x << " " << y << " " << t << "\n"; }
};
int dist(celeb a, celeb b) { return abs(a.x - b.x) + abs(b.y - a.y); }
void solve() {
  int r, n;
  cin >> r >> n;
  vector<celeb> arr(n + 1);
  arr[0].x = 1;
  arr[0].y = 1;
  arr[0].t = 0;
  for (int i = 1; i <= n; i++) {
    int x, y, t;
    cin >> t >> x >> y;
    arr[i].x = x;
    arr[i].y = y;
    arr[i].t = t;
  }
  vector<int> dp(n + 1, 0);
  for (int i = arr.size() - 1; i >= 0; i--) {
    for (int j = i + 1; j < min(arr.size(), 4 * r + i); j++) {
      if (dist(arr[i], arr[j]) <= arr[j].t - arr[i].t) {
        dp[i] = max(dp[j], dp[i]);
      }
    }
    dp[i] += 1;
  }
  cout << dp[0] - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int one_case = 1;
  if (one_case) {
    solve();
  } else {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
      solve();
    }
  }
  return 0;
}

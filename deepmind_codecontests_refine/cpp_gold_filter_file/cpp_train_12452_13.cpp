#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
inline long long int max(long long int a, long long int b) {
  return ((a > b) ? a : b);
}
inline long long int min(long long int a, long long int b) {
  return ((a > b) ? b : a);
}
inline long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long int n = 0, m = 0;
vector<long long int> h, p;
bool check(long long int t) {
  long long int u = 0;
  for (long long int i = 0; i < n; i++) {
    long long int left = h[i] - p[u];
    left = max(0, left);
    if (t < left) {
      return 0;
    }
    long long int right = t - 2 * left;
    right = max(right, 0);
    right = max(right, (t - left) / 2);
    while (u < m && (p[u] <= (h[i] + right))) {
      u++;
    }
    if (u == m) {
      return 1;
    }
  }
  return 0;
}
void sol() {
  long long int len, i;
  cin >> len;
  string s;
  cin >> s;
  for (i = 0; i < len; i++) {
    if (s[i] == 'P') {
      n++;
      h.push_back(i + 1);
    }
  }
  for (i = 0; i < len; i++) {
    if (s[i] == '*') {
      m++;
      p.push_back(i + 1);
    }
  }
  long long int ans = 0;
  long long int l = 0;
  long long int r = 1e18;
  while (l <= r) {
    long long int mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sol();
}

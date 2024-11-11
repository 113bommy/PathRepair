#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long int mod = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int n;
bool check(long long int mid, long long int a, long long int b,
           long long int d[], long long int l[]) {
  for (int i = -1; i < n - mid; ++i) {
    long long int up = d[i + 1] + d[n] - d[i + mid + 1];
    long long int ri = l[i + 1] + l[n] - l[i + mid + 1];
    long long int left = abs(a - ri) + abs(b - up);
    if (left > mid)
      continue;
    else if (left == mid)
      return true;
    else if (left < mid) {
      if ((mid - left) % 2 == 0) return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  string s;
  cin >> s;
  long long int a, b;
  cin >> a >> b;
  long long int maxp = abs(a) + abs(b);
  if (maxp > n) {
    cout << -1 << '\n';
    return 0;
  }
  long long int d[n + 1];
  d[0] = 0;
  for (int i = 0; i < n; ++i) {
    d[i + 1] = d[i];
    if (s[i] == 'D') d[i + 1]--;
    if (s[i] == 'U') d[i + 1]++;
  }
  long long int l[n + 1];
  l[0] = 0;
  for (int i = 0; i < n; ++i) {
    l[i + 1] = l[i];
    if (s[i] == 'L') l[i + 1]--;
    if (s[i] == 'R') l[i + 1]++;
  }
  if (l[n] == a && d[n] == b) {
    cout << 0 << '\n';
    return 0;
  }
  long long int start = 0, end = n, ans = n, check1 = 0;
  while (start < end) {
    long long int mid = (start + end) / 2;
    if (check(mid, a, b, d, l)) {
      check1 = 1;
      end = mid;
      if (ans == end) break;
      ans = end;
    } else {
      start = mid + 1;
    }
  }
  if (check(ans, a, b, d, l)) check1 = 1;
  if (check(ans - 1, a, b, d, l)) ans--, check1 = 1;
  if (check1 == 0) {
    cout << -1 << '\n';
    return 0;
  }
  cout << ans << '\n';
  return 0;
}

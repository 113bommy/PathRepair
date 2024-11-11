#include <bits/stdc++.h>
using namespace std;
vector<long long> ans1, ans2;
bool check(long long a, long long c) {
  long long b;
  b = (c + a * (a * (a - 1)) / 2 - (a * (a - 1) * (2 * a - 1)) / 6) %
      (a * a - (a * (a - 1) / 2));
  if (b == 0)
    return 1;
  else
    return 0;
}
bool check2(long long a, long long b, long long c) {
  long long d;
  d = (a * a * b - a * (a * (a - 1) / 2) - b * (a * (a - 1)) / 2 +
       (a * (a - 1) * (2 * a - 1)) / 6);
  if (c == d)
    return 1;
  else
    return 0;
}
bool over(long long a, long long c) {
  long long b, d;
  b = (c + a * (a * (a - 1)) / 2 - (a * (a - 1) * (2 * a - 1)) / 6) /
      (a * a - (a * (a - 1) / 2));
  d = (a * a * b - a * (a * (a - 1) / 2) - b * (a * (a - 1)) / 2 +
       (a * (a - 1) * (2 * a - 1)) / 6);
  if (d > c)
    return 1;
  else
    return 0;
}
bool over2(long long a, long long c) {
  long long b, d;
  b = 1;
  d = (a * a * b - a * (a * (a - 1) / 2) - b * (a * (a - 1)) / 2 +
       (a * (a - 1) * (2 * a - 1)) / 6);
  if (d > c)
    return 1;
  else
    return 0;
}
bool over3(long long a, long long c) {
  long long b, d;
  b = (c + a * (a * (a - 1)) / 2 - (a * (a - 1) * (2 * a - 1)) / 6) /
      (a * a - (a * (a - 1) / 2));
  if (a > b)
    return 1;
  else
    return 0;
}
long long Go(long long a, long long c) {
  long long b, d;
  b = (c + a * (a * (a - 1)) / 2 - (a * (a - 1) * (2 * a - 1)) / 6) /
      (a * a - (a * (a - 1) / 2));
  return b;
}
int main() {
  long long i, j, k, l;
  long long a, b, c, d;
  long long n;
  cin >> n;
  k = sqrt(n) + 1;
  int ans = 0;
  for (i = 1; i <= k; i++) {
    a = i;
    l = Go(a, n);
    if (a * a > n) break;
    if (over(a, n) == 1) break;
    if (over2(a, n) == 1) break;
    if (over3(a, n) == 1) break;
    if (check(a, n) == 1 && check2(a, l, n) == 1) {
      ans1.push_back(a);
      ans2.push_back(l);
      if (a == l) ans--;
    }
  }
  ans += 2 * ans1.size();
  cout << ans << '\n';
  for (i = 0; i < ans1.size(); i++) {
    cout << ans1[i] << ' ' << ans2[i] << '\n';
  }
  for (i--; i >= 0; i--) {
    if (ans1[i] == ans2[i]) continue;
    cout << ans2[i] << ' ' << ans1[i] << '\n';
  }
}

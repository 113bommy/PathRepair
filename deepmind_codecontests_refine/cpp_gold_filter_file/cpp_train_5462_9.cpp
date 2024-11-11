#include <bits/stdc++.h>
using namespace std;
const int MAXI = numeric_limits<int>::max() / 2;
const int MINI = numeric_limits<int>::min() / 2;
const long long MAXL = numeric_limits<long long>::max() / 2;
const long long MINL = numeric_limits<long long>::min() / 2;
int cnt[2][2];
long long pro(long long s, int &s1, int &s2) {
  while (s % 2 == 0) {
    ++s1;
    s /= 2;
  }
  while (s % 3 == 0) {
    ++s2;
    s /= 3;
  }
  return s;
}
int solve(int &s1, int &s2, int t, long long &a, long long &b) {
  int ans = 0;
  while (s1 > t) {
    --s1;
    ++s2;
    ++ans;
    if (a % 3 == 0)
      a = a * 2 / 3;
    else
      b = b * 2 / 3;
  }
  return ans;
}
int solve(int &s1, int &s2, long long &a, long long &b) {
  int ans = 0;
  while (s1 > s2) {
    --s1;
    ++ans;
    if (a % 2 == 0)
      a /= 2;
    else
      b /= 2;
  }
  return ans;
}
int main(int argc, char *argv[]) {
  long long a, b, c, d, s, t;
  cin >> a >> b >> c >> d;
  s = a * b;
  t = c * d;
  if (pro(s, cnt[0][0], cnt[0][1]) != pro(t, cnt[1][0], cnt[1][1]))
    cout << -1 << endl;
  else {
    int ans = cnt[0][1] > cnt[1][1]
                  ? solve(cnt[0][1], cnt[0][0], cnt[1][1], a, b)
                  : solve(cnt[1][1], cnt[1][0], cnt[0][1], c, d);
    ans += cnt[0][0] > cnt[1][0] ? solve(cnt[0][0], cnt[1][0], a, b)
                                 : solve(cnt[1][0], cnt[0][0], c, d);
    cout << ans << endl;
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
  }
  return 0;
}

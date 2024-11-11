#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, p;
  string str;
  cin >> n >> p;
  cin >> str;
  p = p - 1;
  if (p >= (n / 2)) {
    reverse(str.begin(), str.end());
    p = n - p - 1;
  }
  long long l = p;
  long long r = p;
  for (long long i = p + 1; i < (n / 2); i++) {
    if (str[i] != str[n - i - 1]) {
      r = i;
    }
  }
  for (long long j = p - 1; j >= 0; j--) {
    if (str[j] != str[n - j - 1]) {
      l = j;
    }
  }
  long long left = p - l;
  long long right = r - p;
  long long ans = 0;
  long long cnt = 0;
  for (long long i = p; i >= l; i--) {
    if (str[i] != str[n - i - 1]) {
      ans += cnt;
      cnt = 0;
      long long clicks = min({abs(str[i] - str[n - i - 1]),
                              122 - str[i] + str[n - i - 1] - 97 + 1,
                              122 - str[n - i - 1] + str[i] - 97 + 1});
      ans += clicks;
    }
    cnt++;
  }
  for (long long i = p + 1; i <= r; i++) {
    if (str[i] != str[n - i - 1]) {
      ans += cnt;
      cnt = 0;
      ans += min({abs(str[i] - str[n - i - 1]),
                  122 - str[i] + str[n - i - 1] - 97 + 1,
                  122 - str[n - i - 1] + str[i] - 97 + 1});
    }
    cnt++;
  }
  if (left < right) {
    ans += left;
  } else {
    ans += right;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long swap(long long *x, long long *y) {
  long long temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, x, y, m, n, ans = 0, count = 0;
  vector<long long> left(26, 0);
  vector<long long> right(26, 0);
  vector<long long> mid(26, 0);
  vector<long long> diff(26);
  long long a[26] = {0}, f = 0, min1, min2;
  string s;
  cin >> s;
  k = s.size();
  long long pos;
  long long max1 = 0;
  for (i = 0; i < 26; i++) {
    min1 = 1000001;
    min2 = 1000001;
    max1 = 0;
    f = 0;
    for (j = 0; j < k; j++) {
      if (s[j] - 97 == i) {
        f = 1;
        if (j + 1 < min1) {
          left[i] = j + 1;
          min1 = j + 1;
          pos = j + 1;
        }
        if (k - j < min2) {
          right[i] = k - j;
          min2 = k - j;
        }
        mid[i] = max(mid[i], (j + 1) - pos);
        pos = j + 1;
      }
    }
  }
  ans = 1000001;
  long long ans1;
  for (i = 0; i < 26; i++) {
    if (mid[i] == 0 && left[i] != 0) {
      ans = min(ans, max(left[i], k - left[i] + 1));
    } else if (mid[i] > left[i] && mid[i] > right[i]) {
      ans1 = mid[i];
      ans = min(ans, ans1);
    } else if (left[i] != 0) {
      ans1 = max(left[i], right[i]);
      ans = min(ans, ans1);
    }
  }
  cout << ans << endl;
  return 0;
}

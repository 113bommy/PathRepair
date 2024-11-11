#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
int main() {
  long long int t, i, j, k, n, m;
  scanf("%lld", &t);
  vector<pair<long long int, long long int> > v;
  for (i = 1; i < 10001; i++) {
    for (j = i; j < 10001; j += i) {
      v.push_back(make_pair(i, j));
    }
  }
  while (t--) {
    long long int a, b, c, ans = INT_MAX, ans1, ans2, ans3;
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    for (i = 0; i < v.size(); i++) {
      n = c % v[i].second;
      m = (v[i].second - n) % v[i].second;
      if ((c - n) == 0) n = INT_MAX;
      k = abs(v[i].first - a) + abs(v[i].second - b) + min(m, n);
      if (ans > k) {
        ans = k;
        ans1 = v[i].first;
        ans2 = v[i].second;
        if (m < n)
          ans3 = c + m;
        else
          ans3 = c - n;
      }
    }
    cout << ans << endl;
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
  }
  return 0;
}

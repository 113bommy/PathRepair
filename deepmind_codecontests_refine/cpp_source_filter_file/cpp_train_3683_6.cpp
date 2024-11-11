#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int n, m;
vector<pair<long long, int> > dv;
long long calc(int idx, long long num) {
  if (idx == dv.size()) {
    long long res = 0;
    while (num < n) {
      res += n - num;
      num *= 2;
    }
    return res;
  }
  long long res = 0;
  for (int i = 0; i <= dv[idx].second; i++) {
    res += calc(idx + 1, num);
    num *= dv[i].first;
  }
  return res;
}
int main() {
  cin >> m >> n;
  int x = 0, t;
  for (int i = 0; i < m; i++) {
    cin >> t;
    t--;
    x = gcd(x, t);
  }
  while (x % 2 == 0) x /= 2;
  for (int i = 2; i * i <= x; i++) {
    int cnt = 0;
    while (x % i == 0) {
      cnt++;
      x /= i;
    }
    if (cnt > 0) dv.push_back(pair<long long, int>(i, cnt));
  }
  if (x > 1) dv.push_back(pair<long long, int>(x, 1));
  long long res = calc(0, 1);
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, i, m, g, a, k, b, c, flag, val = 0, h, t, f, q, l, r, y1, j, x1,
                                          x, e, x0, x2, y2, w, y, p, v, d, u,
                                          num, maxval = LLONG_MIN;
  cin >> n;
  map<long long, long long> occ;
  vector<long long> arr;
  while (n--) {
    cin >> a;
    if (sqrtl(a) == floor(sqrtl(a))) {
      val = sqrtl(a);
      if (sqrtl(val) == floor(sqrtl(val)))
        occ[sqrtl(val)] += 4;
      else
        occ[val] += 2;
    } else {
      if (cbrtl(a) == floor(cbrtl(a)))
        occ[cbrtl(a)] += 3;
      else
        arr.push_back(a);
    }
  }
  long long ans = 1;
  for (i = 0; i < arr.size(); i++) {
    for (j = i + 1; j < arr.size(); j++) {
      if (arr[i] != arr[j]) {
        val = gcd(arr[i], arr[j]);
        if (val != 1) occ[val] = occ[val];
      }
    }
  }
  vector<long long> cand;
  for (auto e : occ) cand.push_back(e.first);
  for (i = 0; i < arr.size(); i++) {
    flag = 0;
    for (auto e : cand) {
      if (arr[i] % e == 0) {
        occ[e]++;
        occ[arr[i] / e]++;
        flag = 1;
        break;
      }
    }
    if (!flag) occ[arr[i]]--;
  }
  for (auto e : occ) {
    if (e.second > 0)
      ans = (ans * (e.second + 1)) % 998244353;
    else {
      ans = (ans * (1 - e.second)) % 998244353;
      ans = (ans * (1 - e.second)) % 998244353;
    }
  }
  cout << ans;
  return 0;
}

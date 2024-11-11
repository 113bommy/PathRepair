#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0 || b == 0) return 0;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int getcount(int days, map<int, int> make_pair) {
  int num = 0;
  for (auto it = make_pair.begin(); it != make_pair.end(); it++) {
    num += (it->second) / days;
  }
  return num;
}
int main() {
  long long int n, maxm = 0, k, i, j, m;
  cin >> n >> m;
  vector<int> a(m);
  map<int, int> make_pair;
  for (i = 0; i < m; i++) {
    cin >> a[i];
    make_pair[a[i]]++;
  }
  for (auto it = make_pair.begin(); it != make_pair.end(); it++) {
    maxm += it->second;
  }
  int lo = 1, mid, hi = maxm, res = 0, mid2, k2;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    k = getcount(mid, make_pair);
    if (k == n) {
      mid2 = mid + 1 + (hi - mid - 1) / 2;
      k2 = getcount(mid2, make_pair);
      if (k2 <= n) {
        lo = mid + 1;
        continue;
      } else {
        res = mid;
        lo = mid + 1;
        break;
      }
    }
    if (k < n) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo - 1 << endl;
  return 0;
}

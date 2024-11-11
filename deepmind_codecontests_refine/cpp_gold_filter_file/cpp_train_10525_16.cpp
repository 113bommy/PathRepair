#include <bits/stdc++.h>
using namespace std;
vector<long long> a, x;
vector<long long> minb, maxb;
vector<long long> v;
int main() {
  int n;
  long long t;
  cin >> n >> t;
  long long llmax = std::numeric_limits<long long>::max();
  a.assign(n + 1, 0);
  x.assign(n + 1, 0);
  minb.assign(n + 1, 0);
  maxb.assign(n + 1, llmax);
  v.assign(n + 2, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) {
    minb[i] = a[i] + t;
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] > i) {
      v[i]++;
      v[x[i]]--;
      if (x[i] != n) {
        maxb[x[i]] = min(maxb[x[i]], a[x[i] + 1] + t - 1);
      }
    } else if (x[i] < i) {
      minb[x[i]] = max(minb[x[i]], a[i] + t);
      maxb[x[i]] = min(maxb[x[i]], a[x[i]] + t - 1);
    } else if (x[i] == i && i < n) {
      maxb[i] = min(maxb[i], a[i + 1] + t - 1);
    }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += v[i];
    if (sum > 0) {
      minb[i] = max(minb[i], a[i + 1] + t);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (minb[i] > maxb[i] || (i < n && maxb[i + 1] <= minb[i])) {
      cout << "No" << endl;
      return 0;
    }
  }
  long long prev = 0;
  string ans = "";
  for (int i = 1; i <= n; i++) {
    if (prev < minb[i]) {
      ans += to_string(minb[i]);
      prev = minb[i];
    } else {
      if (prev + 1 > maxb[i]) {
        cout << "No" << endl;
        return 0;
      } else {
        ans += to_string(prev + 1);
        prev++;
      }
    }
    ans += " ";
  }
  cout << "Yes" << endl;
  cout << ans << endl;
  return 0;
}

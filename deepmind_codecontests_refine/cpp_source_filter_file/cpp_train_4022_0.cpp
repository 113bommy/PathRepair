#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, a, d;
  cin >> n >> m >> a >> d;
  set<long long> ts;
  for (int i = 0; i < m; i++) {
    long long x;
    cin >> x;
    ts.insert(x);
  }
  long long lastr = a * n;
  ts.insert(lastr);
  vector<long long> v(ts.begin(), ts.end());
  long long ans = 0;
  long long q = 0;
  for (int i = 0; i < v.size(); i++) {
    long long curr = v[i];
    if (curr <= q) {
      continue;
    }
    long long covered = q / a * a;
    long long first_uncovered = covered + a;
    if (first_uncovered <= curr) {
      long long last_uncovered = curr / a * a;
      last_uncovered = min(last_uncovered, lastr);
      if (last_uncovered >= first_uncovered) {
        long long last_index = last_uncovered / a;
        long long first_index = first_uncovered / a;
        long long k = (d + a) / a;
        long long count = last_index - first_index + 1;
        long long ez_intervals = (count - 1) / k;
        ans += ez_intervals;
        long long new_first = first_uncovered + ez_intervals * a;
        ans++;
        q = new_first + d;
      }
    }
    if (q < curr) {
      ans++;
      q = curr + d;
    }
  }
  cout << ans << endl;
  return 0;
}

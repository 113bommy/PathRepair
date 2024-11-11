#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, w;
  cin >> n >> w;
  long long x = (w + 1) / 2;
  long long y = w;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < n; i++) {
    long long inp;
    cin >> inp;
    if (inp <= y) v.push_back({inp, i + 1});
  }
  sort(v.begin(), v.end());
  long long si = (long long)(v.size());
  if (si == 0) {
    cout << -1 << '\n';
    return;
  }
  long long sum = 0;
  for (long long i = 0; i < si; i++) {
    if (v[i].first >= x && v[i].first <= y) {
      cout << 1 << '\n' << v[i].second << '\n';
      return;
    }
    sum += v[i].first;
  }
  if (sum < x) {
    cout << "-1\n";
    return;
  } else if (sum >= x && sum <= y) {
    cout << si << '\n';
    for (auto it : v) {
      cout << it.second << ' ';
    }
    cout << '\n';
    return;
  }
  long long l = 0;
  long long r = 0;
  sum = 0;
  while (l <= r && r < si) {
    if (sum >= x && sum <= y) {
      break;
    } else if (sum > y) {
      sum -= v[l].first;
      l++;
    } else {
      sum += v[r].first;
      r++;
    }
  }
  cout << (r - l) << '\n';
  for (long long i = l; i < r; i++) {
    cout << v[i].second << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

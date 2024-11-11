#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  vector<pair<long long, long long> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  long long mx = 0;
  long long cursum = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    while (r < n && v[r].first - v[i].first <= d) {
      cursum += v[r].second;
      r++;
    }
    mx = max(mx, cursum);
    cursum -= v[i].second;
  }
  cout << mx;
  return 0;
}

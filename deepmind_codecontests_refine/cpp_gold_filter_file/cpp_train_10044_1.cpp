#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<long long, int> > v;
  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%I64d%I64d", &x, &y);
    v.push_back(make_pair(x + y, y * 2));
  }
  sort(v.begin(), v.end());
  long long last = -1e18;
  int cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    long long x = v[i].first, y = v[i].second;
    if (x - y >= last) {
      last = x;
      cnt++;
    }
  }
  cout << cnt;
}

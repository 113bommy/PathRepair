#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  long long ans = 0;
  vector<pair<int, int> > v;
  for (int b = 1; b <= n; b++) {
    ans += min(m, b < 3000 ? b * b : m) * 2;
    int k = 0;
    if (b < 3000 && b * b <= m) {
      k = b;
    } else {
      k = b - sqrt(1. * b * b - m) - 1;
      while (k * (2 * b - k) <= m) k++;
      k--;
    }
    if (k > 0) {
      ans -= 2 * k;
      v.push_back(make_pair(1, k));
      v.push_back(make_pair(2 * b - k, 2 * b - 1));
    }
  }
  sort(v.begin(), v.end());
  int t = -1;
  for (int i = 0; i < (int)(v.size()); i++) {
    if (t >= 0 && v[t].second >= v[i].first) {
      v[t].second = v[i].second;
    } else {
      v[++t] = v[i];
    }
  }
  for (int i = 0; i < (int)(t + 1); i++) {
    ans += v[i].second - v[i].first + 1;
  }
  cout << ans << endl;
  return 0;
}

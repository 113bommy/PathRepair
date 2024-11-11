#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, ans = 0;
  int a[1000000], c[1000000];
  vector<pair<long long int, long long int> > v;
  memset(a, 0, sizeof(a));
  memset(c, 0, sizeof(c));
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  for (int i = n - m * k; i < v.size(); i++) {
    c[v[i].second] = 1;
    ans += v[i].first;
  }
  cout << ans << endl;
  long long int cnt = 0, tp = 0;
  for (int i = 0; i < n; i++) {
    cnt += c[i];
    if (cnt == m) {
      cnt = 0;
      tp++;
      if (tp < k) {
        cout << i << " ";
      }
    }
  }
  cout << endl;
}

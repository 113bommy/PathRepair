#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
bool v[101];
long long inter(vector<pair<long long, long long> > a) {
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      if (a[i].second < a[j].second && a[i].second > a[j].first) {
        ans++;
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i++) {
      v[i] = false;
    }
    vector<pair<long long, long long> > a;
    for (int i = 0; i < k; i++) {
      long long x, y;
      cin >> x >> y;
      if (x < y) {
        a.push_back(make_pair(x, y));
      } else {
        a.push_back(make_pair(y, x));
      }
      v[x] = true;
      v[y] = true;
    }
    vector<long long> leftover;
    for (int i = 1; i <= 2 * n; i++) {
      if (!v[i]) {
        leftover.push_back(i);
      }
    }
    for (int i = 0; i < (n - k); i++) {
      a.push_back(make_pair(leftover[i], leftover[i + (n - k)]));
    }
    sort(a.begin(), a.end());
    cout << inter(a) << endl;
  }
  cout.flush();
  return 0;
}

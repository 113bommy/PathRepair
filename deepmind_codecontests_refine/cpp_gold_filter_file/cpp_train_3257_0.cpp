#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    long long int n, w, fl = 0, l;
    cin >> n >> w;
    l = (long long int)ceil(w / 2.0);
    vector<pair<long long int, long long int>> v(n + 1);
    for (long long int i = 1; i <= n; i++) {
      cin >> v[i].first;
      v[i].second = i;
      if (v[i].first >= l && v[i].first <= w) fl = i;
    }
    if (fl != 0) {
      cout << "1\n";
      cout << fl << "\n";
    } else {
      sort(v.begin(), v.end());
      long long int i = 1;
      while (i <= n && v[i].first < l) i++;
      i--;
      long long int s = 0;
      vector<long long int> res;
      while (i >= 1 && s < l) {
        s += v[i].first;
        res.push_back(v[i].second);
        i--;
      }
      if (s >= l) {
        cout << res.size() << "\n";
        for (i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << "\n";
      } else
        cout << "-1\n";
    }
  }
}

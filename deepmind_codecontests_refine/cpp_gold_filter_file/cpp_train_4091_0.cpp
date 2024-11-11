#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, w, half;
    int run = 1;
    cin >> n >> w;
    if (w % 2 != 0) {
      half = w / 2 + 1;
    } else {
      half = w / 2;
    }
    vector<pair<long long, long long> > v;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if ((x >= half && x <= w) && run) {
        cout << 1 << endl;
        cout << i + 1 << endl;
        run = 0;
      }
      v.push_back(make_pair(x, i + 1));
    }
    if (run) {
      sort(v.begin(), v.end());
      long long sum = 0, m = 0;
      for (long long i = 0; i < n; i++) {
        if (sum < half && v[i].first < half) {
          sum += v[i].first;
          m++;
        } else {
          break;
        }
      }
      if (sum >= half) {
        cout << m << endl;
        for (long long i = 0; i < m; i++) {
          cout << v[i].second << " ";
        }
        cout << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}

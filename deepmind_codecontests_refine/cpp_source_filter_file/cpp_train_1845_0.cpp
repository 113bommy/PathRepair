#include <bits/stdc++.h>
using namespace std;
long ma = 10000000;
bool a[10000001];
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  c_p_c();
  long long k;
  cin >> k;
  vector<pair<long, pair<long, long> > > a;
  for (long t = 0; t < k; t++) {
    long long n;
    cin >> n;
    vector<long> v;
    for (long i = 1; i <= n; i++) {
      long x;
      cin >> x;
      v.push_back(x);
    }
    long long sum = accumulate(v.begin(), v.end(), 0);
    for (long i = 0; i < (long)v.size(); i++) {
      a.push_back(make_pair(sum - v[i], make_pair(t, i)));
    }
  }
  sort(a.begin(), a.end());
  for (long i = 0; i < (long)a.size() - 1; i++) {
    if (a[i].first == a[i + 1].first &&
        (a[i].second.first != a[i + 1].second.first)) {
      cout << "YES" << endl;
      cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
      cout << a[i + 1].second.first + 1 << " " << a[i].second.second + 1
           << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

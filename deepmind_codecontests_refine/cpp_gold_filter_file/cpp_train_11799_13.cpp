#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, t;
  cin >> n >> t;
  vector<long long> x;
  vector<long long> a;
  vector<double> space;
  vector<pair<long long, long long> > v;
  for (int i = 0; i < n; i++) {
    long long p, q;
    cin >> p >> q;
    v.push_back(make_pair(p, q));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    x.push_back(v[i].first);
    a.push_back(v[i].second);
  }
  for (int i = 0; i < n - 1; i++) {
    double k;
    k = (x[i + 1] - x[i]) - (a[i] + a[i + 1]) / 2.0;
    space.push_back(k);
  }
  int count = 2;
  for (int i = 0; i < space.size(); i++) {
    if (space[i] > t) {
      count = count + 2;
    }
    if (space[i] == t) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}

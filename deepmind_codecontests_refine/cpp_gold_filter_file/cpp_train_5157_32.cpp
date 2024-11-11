#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
long long vec(long long i) {
  long long ll = (v[i].first * v[i + 1].second - v[i + 1].first * v[i].second);
  return ll;
}
int main() {
  long long n;
  cin >> n;
  ++n;
  v = vector<pair<long long, long long> >(n, pair<long long, long long>(0, 0));
  for (long long i = 0; i < n; ++i) {
    pair<long long, long long> a;
    cin >> a.first >> a.second;
    v[i] = a;
    if (i != 0) {
      a.first -= v[i - 1].first;
      a.second -= v[i - 1].second;
      v[i - 1] = a;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n - 2; ++i) {
    if (vec(i) > 0) ++ans;
  }
  cout << ans << endl;
}

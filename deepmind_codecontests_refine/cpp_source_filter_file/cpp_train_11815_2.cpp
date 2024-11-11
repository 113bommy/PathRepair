#include <bits/stdc++.h>
using namespace std;
long long n, S, d[100005];
int main() {
  cin >> n >> S;
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> d[i];
    sum += d[i];
  }
  long long ans = 0;
  vector<pair<long long, long long> > v;
  for (long long i = 1; i <= n; i++) {
    long long mx = sum - d[i], mn = n - 1;
    long long a = S - mx, b = S - mn;
    if (a > b) swap(a, b);
    v.push_back(make_pair(a, b));
    v.push_back(make_pair(1, d[i]));
    sort(v.begin(), v.end());
    long long pos = 0;
    if (v[0].second >= v[1].second) {
      pos = (v[1].second - v[1].first + 1);
    } else if (v[0].second >= v[1].first) {
      pos = -v[1].first + v[0].second + 1;
    }
    v.clear();
    printf("%lld ", d[i] - pos);
  }
}

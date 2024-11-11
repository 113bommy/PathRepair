#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  vector<pair<long long, long long> > v;
  long long ans[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
    ans[i] = -1;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ans[v[0].second] = 0;
  for (long long i = 1; i < n; i++) {
    long long k = 0;
    for (long long j = v[i].second + v[i].first; j < n; j += v[i].first) {
      if (ans[j] == 0) {
        ans[v[i].second] = 1;
        k = 1;
        break;
      }
    }
    if (k == 1) {
      continue;
    }
    for (long long j = v[i].second + v[i].first; j >= 0; j -= v[i].first) {
      if (ans[j] == 0) {
        ans[v[i].second] = 1;
        k = 1;
        break;
      }
    }
    if (k == 0) {
      ans[v[i].second] = 0;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (ans[i] == 1) {
      cout << 'A';
    } else {
      cout << 'B';
    }
  }
}

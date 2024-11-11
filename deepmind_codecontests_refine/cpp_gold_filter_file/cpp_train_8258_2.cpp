#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:400000000")
long long n, k, b, ans, slope;
vector<pair<pair<long long, long long>, long long> > v;
bool comp(pair<pair<long long, long long>, long long> a,
          pair<pair<long long, long long>, long long> b) {
  return a.first.second * b.first.first < a.first.first * b.first.second;
}
bool equal(pair<pair<long long, long long>, long long> a,
           pair<pair<long long, long long>, long long> b) {
  return a.first.second * b.first.first == a.first.first * b.first.second;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k >> b;
    if (k > 0) {
      v.push_back(make_pair(make_pair(k, -b), 1));
    }
    if (k < 0) {
      v.push_back(make_pair(make_pair(-k, b), 1));
      slope += k;
    }
  }
  v.push_back(make_pair(make_pair(1, 1000000007LL * 2), 0));
  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < v.size() - 1; i++) {
    long long newslope = slope;
    newslope += v[i].first.first * v[i].second;
    while (equal(v[i], v[i + 1])) {
      i++;
      newslope += v[i].first.first * v[i].second;
    }
    if (newslope != slope) ans++, slope = newslope;
  }
  cout << ans;
}

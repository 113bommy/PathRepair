#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const long long mod = 1000000007;
long long dist(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (p1.first - p2.first) * (p1.first - p2.first) +
         (p1.second - p2.second) * (p1.second - p2.second);
}
int main() {
  int n;
  cin >> n;
  pair<long long, long long> f1, f2;
  cin >> f1.first >> f1.second >> f2.first >> f2.second;
  vector<pair<long long, int> > F1;
  long long F2[2222];
  pair<long long, long long> p;
  for (int i = 0; i < n; i++) {
    cin >> p.first >> p.second;
    F1.push_back(make_pair(dist(f1, p), i));
    F2[i] = dist(f2, p);
  }
  sort(F1.begin(), F1.end());
  long long total = (long long)(1e19);
  for (int i = 0; i < F1.size(); i++) {
    long long maximum = 0;
    for (int j = i + 1; j < F1.size(); j++) {
      if (F1[j].first == F1[i].first) continue;
      maximum = max(maximum, F2[F1[j].second]);
    }
    total = min(total, maximum + F1[i].first);
  }
  total = min(total, *max_element(F2, F2 + n));
  cout << total << endl;
}

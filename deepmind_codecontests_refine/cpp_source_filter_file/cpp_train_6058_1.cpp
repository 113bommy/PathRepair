#include <bits/stdc++.h>
using namespace std;
bool g(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first < b.first;
}
int main() {
  int n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  for (int i = 0; i < n; i++) cin >> v[i].first;
  for (int i = 0; i < n; i++) cin >> v[i].second;
  sort(v.begin(), v.end(), g);
  long long b = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i].first == v[i + 1].first) {
      b += v[i].second + v[i + 1].second;
      for (int j = 0; j < i; j++) {
        if (((v[j].first ^ v[i].first) & v[j].first) == 0) {
          b += v[j].second;
          v[j].second == 0;
        }
      }
      v[i].second = 0;
      v[i + 1].second = 0;
    }
  }
  cout << b;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int d(0);
  vector<long long>::iterator it;
  for (int i = 0; i < n - 1; i++) {
    it = upper_bound(v.begin() + i, v.end(), v[i] + 5);
    int w = it - v.begin() - i;
    d = max(d, w);
    if (it == v.end()) break;
  }
  cout << d;
  return 0;
}

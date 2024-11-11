#include <bits/stdc++.h>
using namespace std;
int count3(long long x1) {
  int x = x1;
  int ret = 0;
  while (x % 3 == 0) {
    ret++;
    x /= 3;
  }
  return ret;
}
long long n;
int main() {
  cin >> n;
  vector<pair<int, long long>> v;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].second;
    v[i].first = -count3(v[i].second);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) cout << v[i].second << " ";
}

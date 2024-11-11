#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int main() {
  long long a, b, f, k;
  cin >> a >> b >> f >> k;
  if (b / a >= k) {
    cout << 0 << endl;
    return 0;
  }
  v.push_back(f);
  for (long long i = 2;; i += 2) {
    long long r1 = i * a - f;
    long long r2 = i * a + f;
    if (r1 > k * a) break;
    if (r1 <= k * a) v.push_back(r1);
    if (r2 <= k * a) v.push_back(r2);
  }
  v.push_back(k * a);
  if (b < f) {
    cout << -1;
    return 0;
  }
  long long last = 0;
  long long has = b;
  int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    long long dis = v[i] - last;
    if (dis > has) {
      has = b - dis;
      sum++;
    }
    if (has < dis) {
      cout << -1 << endl;
      return 0;
    }
    has -= dis;
    last = v[i];
  }
  cout << sum << endl;
  return 0;
}

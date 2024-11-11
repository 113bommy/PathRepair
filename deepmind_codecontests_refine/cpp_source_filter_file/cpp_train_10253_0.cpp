#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;
  vector<int> v;
  if (v1 > v2) swap(v1, v2);
  for (int i = 0; i < t - 1; ++i) {
    v.push_back(v1 + i * d);
  }
  int sum = 0;
  v.push_back(v2);
  for (int i = t - 1; i > 0; ++i) {
    if (abs(v[i] - v[i - 1]) <= d) break;
    v[i - 1] = v[i] + d;
  }
  for (int i = 0; i < t; ++i) {
    sum += v[i];
  }
  cout << sum;
  return 0;
}

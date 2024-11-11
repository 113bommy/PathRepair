#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n;
  vector<pair<long long, long long>> z;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    z.push_back({a, b});
  }
  sort(z.begin(), z.end());
  b = 0;
  long long m = z[0].second;
  for (int i = 1; i < n; i++) {
    if (z[i].second < m) b = 1;
    a = z[i].second;
    m = max(m, a);
  }
  if (!b)
    cout << "Poor Alex";
  else
    cout << "Happy Alex";
  return 0;
}

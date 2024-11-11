#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n], x[n];
  vector<pair<long long int, long long int>> v;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> x[i];
    v.push_back(make_pair(a[i], x[i]));
  }
  long long int m;
  cin >> m;
  long long int b[m];
  x[m];
  for (long long int i = 0; i < m; i++) {
    cin >> b[i] >> x[i];
    v.push_back(make_pair(b[i], x[i]));
  }
  sort(v.begin(), v.end());
  long long int sum = 0;
  long long int i = 0;
  while (i < v.size()) {
    if (v[i].first == v[i + 1].first) {
      sum += (v[i].second > v[i + 1].second ? v[i].second : v[i + 1].second);
      i++;
    } else
      sum += v[i].second;
    i++;
  }
  cout << sum << "\n";
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > v;
  for (int i = 0; i < m; i++) {
    long long a, b;
    cin >> b >> a;
    v.push_back(make_pair(a, b));
  }
  sort(v.rbegin(), v.rend());
  long long total = 0, i = 0, count = 0;
  while (i < 20 && (count + v[i].second) <= n) {
    total += v[i].first * v[i].second;
    count += v[i].second;
    i++;
  }
  if (i != 20) total += v[i].first * (n - count);
  cout << total << endl;
}

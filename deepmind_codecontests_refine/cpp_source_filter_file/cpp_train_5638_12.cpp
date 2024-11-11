#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> in;
vector<pair<long long, long long>> de;
signed main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    if (a < b)
      in.push_back({a, i});
    else
      de.push_back({a, i});
  }
  sort(in.begin(), in.end(), greater<pair<long long, long long>>());
  sort(de.begin(), de.end());
  if (in.size() > de.size()) {
    cout << in.size() << '\n';
    for (auto i : in) cout << i.second << ' ';
  } else {
    cout << de.size() << '\n';
    for (auto i : in) cout << i.second << ' ';
  }
}

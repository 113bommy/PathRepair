#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char c;
  long long i = 0, j = 0;
  vector<pair<long long, long long>> a;
  vector<long long> b;
  while (cin >> c) {
    a.push_back(make_pair((long long)(c - '0'), i));
    b.push_back((long long)(c - '0'));
    while (a.size() >= 2) {
      if (a[a.size() - 1].first == 0 && a[a.size() - 2].first == 1) {
        a.pop_back();
        a.pop_back();
      } else
        break;
    }
    i++;
  }
  vector<bool> used(b.size(), false);
  for (auto i : a) used[i.second] = true;
  for (long long k = 0; k < b.size(); ++k) {
    if (used[k] && b[k] == 1) {
      cout << 0;
      if (j + 1 < a.size()) j++;
    } else
      cout << b[k];
  }
  return 0;
}

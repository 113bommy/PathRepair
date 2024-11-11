#include <bits/stdc++.h>
using namespace std;
long long n, mx1, mx2, total, p;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if (v[i].second < mx1 && v[i].second > mx2)
      mx2 = v[i].second;
    else if (v[i].second > mx1)
      mx2 = mx1, mx1 = v[i].second, p = i;
    total += v[i].first;
  }
  for (int i = 0; i < n; i++) {
    if (p == i)
      cout << (total - v[i].first) * mx2 << " ";
    else
      cout << (total - v[i].first) * mx1 << " ";
  }
  return 0;
}

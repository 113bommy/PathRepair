#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  pair<int, int> f[100010];
  for (int i = 0; i < n; ++i) {
    cin >> f[i].first;
    f[i].second = i;
  }
  sort(f, f + n);
  int total = 0;
  for (int i = 0; i < n - 1; ++i) {
    total += abs(f[i].second - f[i + 1].second);
  }
  cout << total << '\n';
  return 0;
}

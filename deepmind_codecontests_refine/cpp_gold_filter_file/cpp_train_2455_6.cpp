#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0, first; i < n; i++) cin >> first, a.push_back(first);
  sort(a.begin(), a.end());
  if (n < 3) return cout << a[n - 1], 0;
  return cout << a[n / 2], 0;
}

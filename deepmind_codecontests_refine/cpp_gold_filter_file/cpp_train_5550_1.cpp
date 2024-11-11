#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end(), greater<pair<int, int> >());
  int x = 0, y = 0;
  vector<int> a1, a2;
  for (int i = 0; i < n; i++) {
    if (abs((x + a[i].first) - y) <= a[0].first && (int)a1.size() + 1 <= n / 2)
      x += a[i].first, a1.emplace_back(a[i].second);
    else
      y += a[i].first, a2.emplace_back(a[i].second);
  }
  cout << (int)a1.size() << '\n';
  for (auto& i : a1) cout << i << ' ';
  cout << '\n';
  cout << (int)a2.size() << '\n';
  for (auto& i : a2) cout << i << ' ';
  cout << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.rbegin(), a.rend());
  int need = 0;
  for (int i = 0; i < n; i++) {
    need += a[i].first * i + 1;
  }
  cout << need << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i].second << " ";
  }
  return 0;
}

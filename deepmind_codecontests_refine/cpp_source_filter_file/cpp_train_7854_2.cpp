#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    int q, w;
    cin >> q >> w;
    v[i] = {q, w};
  }
  sort(v.begin(), v.end());
  int day = 0;
  for (int i = 1; i < n; ++i) {
    if (v[i].second >= day) {
      day = v[i].second;
    } else {
      day = v[i].second;
    }
  }
  cout << day << '\n';
}

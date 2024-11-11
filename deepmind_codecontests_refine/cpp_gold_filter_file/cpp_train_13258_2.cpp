#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int> > a;
  long int s, n;
  cin >> s >> n;
  long int b, c;
  for (long int i = 0; i < n; i++) {
    cin >> b >> c;
    a.push_back(make_pair(b, c));
  }
  sort(a.begin(), a.end());
  for (long int i = 0; i < n; i++) {
    if (a[i].first < s) {
      s = s + a[i].second;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

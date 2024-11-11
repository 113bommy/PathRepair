#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  vector<string> v;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  int mn = 6;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int t = 0;
      for (int k = 0; k < 6; ++k)
        if (v[i][k] != v[j][k]) ++t;
      mn = min(mn, t);
    }
  }
  cout << (mn - 1) / 2 << endl;
  return 0;
}

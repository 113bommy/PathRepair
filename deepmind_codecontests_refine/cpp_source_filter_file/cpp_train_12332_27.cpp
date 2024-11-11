#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  map<string, int> a;
  map<int, string> b;
  b[0] = "S";
  b[1] = "M";
  b[2] = "L";
  b[3] = "XL";
  b[4] = "XXL";
  for (auto c : b) {
    a[c.second] = c.first;
  }
  vector<int> d(5);
  for (int i = 0; i < 5; ++i) cin >> d[i];
  int k;
  cin >> k;
  string p;
  for (int i = 0; i < k; ++i) {
    cin >> p;
    for (int j = 0; j < 4; ++j) {
      if (a[p] + j < 5 && d[a[p] + j] > 0) {
        --d[a[p] + j];
        cout << b[a[p] + j];
        j = 4;
      } else if (a[p] - j >= 0 && d[a[p] - j] > 0) {
        --d[a[p] - j];
        cout << b[a[p] - j];
        j = 4;
      }
    }
    cout << '\n';
  }
  return 0;
}

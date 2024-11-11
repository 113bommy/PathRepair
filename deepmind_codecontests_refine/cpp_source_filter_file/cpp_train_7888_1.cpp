#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, s;
  cin >> n;
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    c[i].first = a + b;
    c[i].second = a - b;
  }
  sort(c.begin(), c.end());
  s = 1;
  b = c[0].first;
  for (int i = 1; i < n; i++) {
    if (c[i].second > b) {
      s++;
      b = c[i].first;
    }
  }
  cout << s << endl;
}

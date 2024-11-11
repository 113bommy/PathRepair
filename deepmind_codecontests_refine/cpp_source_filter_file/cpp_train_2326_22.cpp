#include <bits/stdc++.h>
using namespace std;
int d, n, t, s;
int main() {
  cin >> d >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    s += d - t;
  }
  cout << s << endl;
  return (0);
}

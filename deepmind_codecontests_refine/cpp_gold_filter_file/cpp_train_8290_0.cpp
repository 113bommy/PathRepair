#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  string seq;
  cin >> seq;
  vector<string> f(10);
  for (int i = 0; i < 10; ++i) {
    cin >> f[i];
  }
  for (int i = 0; i + 8 <= 80; i += 10) {
    for (int j = 0; j < 10; ++j) {
      if (f[j] == seq.substr(i, 10)) {
        cout << j;
      }
    }
  }
  cout << endl;
  return 0;
}

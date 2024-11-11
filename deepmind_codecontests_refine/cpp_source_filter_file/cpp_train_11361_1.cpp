#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, k, cnt = 0;
    cin >> n >> k;
    string s;
    for (int j = 0; j < n; ++j) {
      s += (char)'a' + cnt;
      ++cnt;
      if (cnt > k) cnt = 0;
    }
    cout << s << "\n";
  }
  return 0;
}

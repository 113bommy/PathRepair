#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s1 = "", s2(m, 'B');
    for (int i = 0; i < m; i++) {
      if (i % 2 == 0)
        s1.push_back('B');
      else
        s1.push_back('W');
    }
    for (int i = 0; i < n - 1; i++) cout << s1 << "\n";
    cout << s2 << "\n";
  }
}

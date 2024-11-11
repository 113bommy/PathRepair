#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt = 1;
  while (tt--) {
    int n;
    cin >> n;
    string pre;
    int c = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (pre != s) c++;
      pre = s;
    }
    cout << c << "\n";
  }
}

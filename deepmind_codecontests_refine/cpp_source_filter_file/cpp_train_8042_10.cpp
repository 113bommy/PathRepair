#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "";
    int z = 0;
    if (n % 4 == 0) {
      z = n / 4;
    } else {
      z = n / 4 + 1;
    }
    string s1 = "";
    for (int i = 0; i < z; i++) {
      s1 += "8";
    }
    string s2 = "";
    for (int i = 0; i < n - z - 1; i++) {
      s2 += "9";
    }
    string ans = s2 + s1;
    cout << ans << endl;
  }
}

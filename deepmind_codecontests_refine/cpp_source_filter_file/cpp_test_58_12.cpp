#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> v;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, n, c;
    cin >> n;
    string s[2];
    for (int i = 0; i < 2; i++) {
      cin >> s[i];
    }
    bool b1 = 1;
    for (int i = 0; i < n; i++) {
      if (s[0][i] == '1' && s[1][i + 1] == '1') {
        b1 = 0;
        cout << "NO";
        break;
      }
    }
    if (b1) cout << "YES";
    cout << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long am;
  cin >> am;
  for (long long qq = 0; qq < am; qq++) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long idl = -1;
    long long idd = 0;
    for (auto nw : s) {
      if (nw == '0') {
        idl = idd;
      }
      idd++;
    }
    if (idl == -1) {
      cout << 1 << " " << s.size() - 1 << " " << 2 << " " << s.size() << "\n";
    } else {
      if (s.size() - (idl + 2) + 1 >= n / 2) {
        cout << idl + 1 << " " << s.size() << " " << idl + 2 << " " << s.size()
             << "\n";
      } else {
        cout << 1 << " " << idl + 1 << " " << 1 << " " << idl << "\n";
      }
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _q;
  cin >> _q;
  string n2 = "222527323335525557727577";
  int sizn2 = n2.size();
  for (int _t = 0; _t < _q; _t++) {
    int k, ans = 0;
    cin >> k;
    cin.ignore();
    string s;
    getline(cin, s);
    int a[10] = {};
    for (int i = 0; i < k; i++) {
      a[s[i] - '0']++;
    }
    if (a[4] != 0)
      cout << 1 << '\n' << 4 << '\n';
    else if (a[1] != 0)
      cout << 1 << '\n' << 1 << '\n';
    else if (a[6] != 0)
      cout << 1 << '\n' << 6 << '\n';
    else if (a[8] != 0)
      cout << 1 << '\n' << 8 << '\n';
    else if (a[9] != 0)
      cout << 1 << '\n' << 9 << '\n';
    else {
      int fl = 0;
      for (int i = 0; i < sizn2; i += 2) {
        int ind1 = s.find(n2[i]);
        if (!(ind1 != string::npos)) continue;
        int ind2 = s.find(n2[i + 1], ind1 + 1);
        if (ind2 != string::npos) {
          cout << 2 << '\n' << n2[i] << n2[i + 1] << '\n';
          fl = 1;
          break;
        }
      }
    }
  }
}

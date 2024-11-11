#include <bits/stdc++.h>
using namespace std;
const int kn = 300005;
const int N = 100001;
const int mod = 1e9 + 7;
int first;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> first;
  while (first--) {
    cin >> s;
    sort(s.begin(), s.end());
    bool ok = true;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1] + 1) {
        ok = false;
        break;
      }
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

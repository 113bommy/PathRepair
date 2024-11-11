#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.substr(s.size() - 2, 2) == "po")
      cout << "FILIPINO\n";
    else if (s.substr(s.size() - 4, 4) == "masu" ||
             s.substr(s.size() - 4, 4) == "dasu")
      cout << "JAPANESE\n";
    else
      cout << "KOREAN\n";
  }
}

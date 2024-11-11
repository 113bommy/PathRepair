#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c = 0;
    string s, t;
    cin >> s;
    t = s;
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++) c += (s[i] != t[i]);
    cout << c << "\n";
  }
}

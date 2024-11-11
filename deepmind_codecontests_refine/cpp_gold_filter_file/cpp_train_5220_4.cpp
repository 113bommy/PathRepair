#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string S;
  cin >> S;
  for (int i = 0; i < S.length(); ++i) {
    string a = S.substr(0, i);
    string b = S.substr(i, S.length() - i);
    string c = b + a;
    string d = c;
    reverse(d.begin(), d.end());
    if (S != c && d == c) {
      cout << 1 << endl;
      return 0;
    }
  }
  bool b = false;
  for (int i = 0; i < S.length() / 2; ++i) {
    if (S[0] != S[i]) {
      string a = S.substr(0, i + 1);
      string b = S.substr(S.length() - i - 1, i + 1);
      if (a != b) {
        cout << 2 << endl;
        return 0;
      }
    }
  }
  cout << "Impossible" << endl;
  return 0;
}

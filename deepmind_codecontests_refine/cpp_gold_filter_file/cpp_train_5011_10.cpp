#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  string s;
  map<long long int, string> mp;
  cin >> n;
  cin >> s;
  string res = "";
  long long int ctn = 0;
  for (long long int i = 0; i < n;) {
    bool ok = false;
    if (s[i] == s[i + 1] && i + 2 < n) {
      if (s[i] == s[i + 2] && s[i] == 'B') {
        ctn++;
        s[i + 1] = 'R';
      } else if (s[i] == 'B' && s[i + 2] == 'R') {
        ctn++;
        s[i + 1] = 'G';
      } else if (s[i] == 'B' && s[i + 2] == 'G') {
        ctn++;
        s[i + 1] = 'R';
      } else if (s[i] == s[i + 2] && s[i] == 'R') {
        ctn++;
        s[i + 1] = 'B';
      } else if (s[i] == 'R' && s[i + 2] == 'B') {
        ctn++;
        s[i + 1] = 'G';
      } else if (s[i] == 'R' && s[i + 2] == 'G') {
        ctn++;
        s[i + 1] = 'B';
      } else if (s[i] == s[i + 2] && s[i + 2] == 'G') {
        ctn++;
        s[i + 1] = 'R';
      } else if (s[i] == 'G' && s[i + 2] == 'B') {
        ctn++;
        s[i + 1] = 'R';
      } else if (s[i] == 'G' && s[i + 2] == 'R') {
        ctn++;
        s[i + 1] = 'B';
      }
      ok = true;
    } else if (s[i] == s[i + 1] && i + 1 < n) {
      if (s[i] == 'B') {
        ctn++;
        s[i + 1] = 'R';
      } else if (s[i] == 'G') {
        ctn++;
        s[i + 1] = 'R';
      } else if (s[i] == 'R') {
        ctn++;
        s[i + 1] = 'B';
      }
    }
    if (ok) {
      i += 2;
    } else {
      i++;
    }
  }
  cout << ctn << endl;
  cout << s << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void c_h_g() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  c_h_g();
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int r = 0, s1 = 0, p = 0;
    for (long long i = 0; i < s.length(); i++) {
      if (s[i] == 'R')
        r += 1;
      else if (s[i] == 'S')
        s1 += 1;
      else
        p += 1;
    }
    map<int, char> make_pair;
    make_pair[r] = 'R';
    make_pair[s1] = 'S';
    make_pair[p] = 'P';
    int z = max(r, max(s1, p));
    char q;
    if (make_pair[z] == 'R') q = 'P';
    if (make_pair[z] == 'S') q = 'R';
    if (make_pair[z] == 'P') q = 'S';
    string z1 = "";
    for (long long i = 0; i < s.length(); i++) z1 += q;
    cout << z1 << endl;
  }
  return 0;
}

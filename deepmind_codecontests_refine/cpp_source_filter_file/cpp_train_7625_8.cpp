#include <bits/stdc++.h>
using namespace std;
long long t;
string s;
map<char, long long> x;
char c;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    x.clear();
    for (long long i = 0; i < s.length(); i++) x[s[i]]++;
    if (x['R'] > x['S'] && x['R'] > x['P'])
      c = 'P';
    else if (x['S'] > x['R'] && x['S'] > x['P'])
      c = 'R';
    else if (x['P'] > x['R'] && x['P'] > x['S'])
      c = 'S';
    for (long long i = 0; i < s.length(); i++) cout << c;
    cout << endl;
  }
}

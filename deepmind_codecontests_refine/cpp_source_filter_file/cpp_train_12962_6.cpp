#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 9;
int v[N];
map<char, char> rev;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  rev['N'] = 'S';
  rev['S'] = 'N';
  rev['W'] = 'E';
  rev['E'] = 'W';
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (auto &x : b) x = rev[x];
  reverse(b.begin(), a.end());
  string f = a + '$' + b;
  for (int i = 1, j = 0; i < (int)f.size(); i++) {
    while (f[i] != f[j] and j > 0) {
      j = v[j - 1];
    }
    if (f[i] == f[j]) {
      j++;
    }
    v[i] = j;
  }
  if (v[f.size() - 1] == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}

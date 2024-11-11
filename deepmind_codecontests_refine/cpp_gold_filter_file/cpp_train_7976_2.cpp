#include <bits/stdc++.h>
using namespace std;
const int N = 3050;
int n;
string s[N];
map<string, int> v;
int val(string &c) {
  int x = 0, l = 0, r = c.size() - 1;
  while (c[l] == '&') l++, x--;
  while (c[r] == '*') r--, x++;
  c = c.substr(l, r - l + 1);
  if (v[c] <= 0) return 0;
  return x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  s[1] = "void";
  v["void"] = 1;
  for (int i = 2; i < N; i++) s[i] = s[i - 1] + "*";
  cin >> n;
  while (n--) {
    string x, y, z;
    cin >> x >> y;
    int c = val(y);
    if (x == "typedef") {
      cin >> z;
      v[z] = c + v[y];
    } else
      cout << ((c + v[y]) <= 0 ? "errtype" : s[c + v[y]]) << '\n';
  }
}

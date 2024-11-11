#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 1e5 + 5;
ll mat[N];
vector<int> v;
int n;
int nikal(int pos) {
  if (pos == n) return 1;
  if (mat[pos] != -1) return mat[pos];
  return mat[pos] = (nikal(pos + 1) * v[pos] + nikal(pos + 1)) % mod;
}
void solve() {
  string s;
  memset(mat, -1, sizeof(mat));
  cin >> s;
  string t;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'b') t.push_back(s[i]);
    ;
  }
  s = t;
  int c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      c++;
    else if (s[i] == 'b') {
      if (c) v.push_back(c);
      c = 0;
    }
  }
  if (c) v.push_back(c);
  n = v.size();
  cout << nikal(0) - 1;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}

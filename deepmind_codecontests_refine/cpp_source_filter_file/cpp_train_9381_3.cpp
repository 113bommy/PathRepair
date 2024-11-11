#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long double PI = acosl(-1);
const int nmax = 1e4 + 5;
map<long long, int> mp;
map<long long, int> idx;
int n, q;
string s[nmax];
long long okkhortonum(char ch) {
  if (ch == '.') return 37;
  if (ch <= '9')
    return ch - '0' + 1;
  else
    return ch - 'a' + 10;
}
long long hprime = 67;
long long hp[9];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  hp[0] = 1;
  for (int i = 1; i < 9; i++) {
    hp[i] = hp[i - 1] * hprime;
  }
  cin >> n;
  for (int k = 0; k < n; k++) {
    map<long long, bool> visited;
    cin >> s[k];
    int len = (int)s[k].size();
    for (int i = 0; i < len; i++) {
      long long hashval = 0;
      for (int j = i; j < len; j++) {
        hashval += hp[j - i + 1] * okkhortonum(s[k][j]);
        if (visited[hashval]) continue;
        mp[hashval]++;
        idx[hashval] = k;
        visited[hashval] = true;
      }
    }
  }
  cin >> q;
  string s2;
  for (int i = 0; i < q; i++) {
    cin >> s2;
    long long hashval = 0;
    for (int j = 0; j < s2.length(); j++) {
      hashval += hp[j + 1] * okkhortonum(s2[j]);
    }
    if (mp[hashval] == 0) {
      cout << "0 -\n";
    } else {
      cout << mp[hashval] << " " << s[idx[hashval]] << "\n";
    }
  }
}
